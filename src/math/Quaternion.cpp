/*!
 * \file src/math/Quaternion.cpp
 * \brief Quaternion
 *
 * \author Mongoose
 */

#include <math.h>

#include "global.h"
#include "math/Quaternion.h"

Quaternion::Quaternion() {
    mW = 0;
    mX = 0;
    mY = 0;
    mZ = 0;
}

Quaternion::Quaternion(float w, float x, float y, float z) {
    mW = w;
    mX = x;
    mY = y;
    mZ = z;
}

Quaternion::Quaternion(float v[4]) {
    mW = v[0];
    mX = v[1];
    mY = v[2];
    mZ = v[3];
}

void Quaternion::getMatrix(float m[16]) {
    m[ 0] = 1.0f - 2.0f * (mY*mY + mZ*mZ);
    m[ 1] = 2.0f * (mX*mY - mW*mZ);
    m[ 2] = 2.0f * (mX*mZ + mW*mY);
    m[ 3] = 0.0f;

    m[ 4] = 2.0f * (mX*mY + mW*mZ);
    m[ 5] = 1.0f - 2.0f * (mX*mX + mZ*mZ);
    m[ 6] = 2.0f * (mY*mZ - mW*mX);
    m[ 7] = 0.0f;

    m[ 8] = 2.0f * (mX*mZ - mW*mY);
    m[ 9] = 2.0f * (mY*mZ + mW*mX);
    m[10] = 1.0f - 2.0f * (mX*mX + mY*mY);
    m[11] = 0.0f;

    m[12] = 0.0f;
    m[13] = 0.0f;
    m[14] = 0.0f;
    m[15] = 1.0f;
}

Quaternion Quaternion::operator *(const Quaternion &q) {
    return multiply(*this, q);
}

Quaternion Quaternion::operator /(const Quaternion &q) {
    return divide(*this, q);
}

Quaternion Quaternion::operator +(const Quaternion &q) {
    return add(*this, q);
}

Quaternion Quaternion::operator -(const Quaternion &q) {
    return subtract(*this, q);
}

bool Quaternion::operator ==(const Quaternion &q) {
    //return (mX == q.mX && mY == q.mY && mZ == q.mZ && mW == q.mW);
    return (equalEpsilon(mX, q.mX) && equalEpsilon(mY, q.mY) &&
            equalEpsilon(mZ, q.mZ) && equalEpsilon(mW, q.mW));
}

Quaternion Quaternion::conjugate() {
    return Quaternion(mW, -mX, -mY, -mZ);
}

Quaternion Quaternion::scale(float s) {
    return Quaternion(mW * s, mX * s, mY * s, mZ * s);
}

Quaternion Quaternion::inverse() {
    return conjugate().scale(1/magnitude());
}

float Quaternion::dot(Quaternion a, Quaternion b) {
    return ((a.mW * b.mW) + (a.mX * b.mX) + (a.mY * b.mY) + (a.mZ * b.mZ));
}

float Quaternion::magnitude() {
    return sqrtf(dot(*this, *this));
}

void Quaternion::setIdentity() {
    mW = 1.0;
    mX = 0.0;
    mY = 0.0;
    mZ = 0.0;
}

void Quaternion::set(float angle, float x, float y, float z) {
    float temp, dist;

    // Normalize
    temp = x*x + y*y + z*z;

    dist = 1.0f / sqrtf(temp);

    x *= dist;
    y *= dist;
    z *= dist;

    mX = x;
    mY = y;
    mZ = z;

    mW = cosf(angle / 2.0f);
}

void Quaternion::normalize() {
    float dist, square;

    square = mX * mX + mY * mY + mZ * mZ + mW * mW;

    if (square > 0.0) {
        dist = 1.0f / sqrtf(square);
    } else {
        dist = 1;
    }

    mX *= dist;
    mY *= dist;
    mZ *= dist;
    mW *= dist;
}

void Quaternion::copy(Quaternion q) {
    mW = q.mW;
    mX = q.mX;
    mY = q.mY;
    mZ = q.mZ;
}

Quaternion Quaternion::slerp(Quaternion a, Quaternion b, float time) {
    /*******************************************************************
     * Spherical Linear Interpolation algorthim
     *-----------------------------------------------------------------
     *
     * Interpolate between A and B rotations ( Find qI )
     *
     * qI = (((qB . qA)^ -1)^ Time) qA
     *
     * http://www.magic-software.com/Documentation/quat.pdf
     *
     * Thanks to digiben for algorithms and basis of the notes in
     * this func
     *
     *******************************************************************/

    float result, scaleA, scaleB;
    Quaternion i;


    // Don't bother if it's the same rotation, it's the same as the result
    if (a == b)
        return a;

    // A . B
    result = dot(a, b);

    // If the dot product is less than 0, the angle is greater than 90 degrees
    if (result < 0.0f) {
        // Negate quaternion B and the result of the dot product
        b = Quaternion(-b.mW, -b.mX, -b.mY, -b.mZ);
        result = -result;
    }

    // Set the first and second scale for the interpolation
    scaleA = 1 - time;
    scaleB = time;

    // Next, we want to actually calculate the spherical interpolation.  Since this
    // calculation is quite computationally expensive, we want to only perform it
    // if the angle between the 2 quaternions is large enough to warrant it.  If the
    // angle is fairly small, we can actually just do a simpler linear interpolation
    // of the 2 quaternions, and skip all the complex math.  We create a "delta" value
    // of 0.1 to say that if the cosine of the angle (result of the dot product) between
    // the 2 quaternions is smaller than 0.1, then we do NOT want to perform the full on
    // interpolation using.  This is because you won't really notice the difference.

    // Check if the angle between the 2 quaternions was big enough
    // to warrant such calculations
    if (1 - result > 0.1f) {
        // Get the angle between the 2 quaternions, and then
        // store the sin() of that angle
        float theta = (float)acos(result);
        float sinTheta = (float)sin(theta);

        // Calculate the scale for qA and qB, according to
        // the angle and it's sine value
        scaleA = (float)sin((1 - time) * theta) / sinTheta;
        scaleB = (float)sin((time * theta)) / sinTheta;
    }

    // Calculate the x, y, z and w values for the quaternion by using a special
    // form of linear interpolation for quaternions.
    return (a.scale(scaleA) + b.scale(scaleB));
}

void Quaternion::setByMatrix(float matrix[16]) {
    float diagonal = matrix[0] + matrix[5] + matrix[10] + 1.0f;
    float scale = 0.0f;
    float w = 0.0f, x = 0.0f, y = 0.0f, z = 0.0f;

    if (diagonal > 0.00000001) {
        // Calculate the scale of the diagonal
        scale = (float)(sqrt(diagonal) * 2);

        w = 0.25f * scale;
        x = (matrix[9] - matrix[6]) / scale;
        y = (matrix[2] - matrix[8]) / scale;
        z = (matrix[4] - matrix[1]) / scale;
    } else {
        // If the first element of the diagonal is the greatest value
        if (matrix[0] > matrix[5] && matrix[0] > matrix[10]) {
            // Find the scale according to the first element, and double it
            scale = (float)sqrt(1.0f + matrix[0] - matrix[5] - matrix[10])*2.0f;

            // Calculate the quaternion
            w = (matrix[9] - matrix[6]) / scale;
            x = 0.25f * scale;
            y = (matrix[4] + matrix[1]) / scale;
            z = (matrix[2] + matrix[8]) / scale;
        } else if (matrix[5] > matrix[10]) {
            // The second element of the diagonal is the greatest value
            // Find the scale according to the second element, and double it
            scale = (float)sqrt(1.0f + matrix[5] - matrix[0] - matrix[10])*2.0f;

            // Calculate the quaternion
            w = (matrix[2] - matrix[8]) / scale;
            x = (matrix[4] + matrix[1]) / scale;
            y = 0.25f * scale;
            z = (matrix[9] + matrix[6]) / scale;
        } else { // The third element of the diagonal is the greatest value
            // Find the scale according to the third element, and double it
            scale = (float)sqrt(1.0f + matrix[10] - matrix[0] - matrix[5])*2.0f;

            // Calculate the quaternion
            w = (matrix[4] - matrix[1]) / scale;
            x = (matrix[2] + matrix[8]) / scale;
            y = (matrix[9] + matrix[6]) / scale;
            z = 0.25f * scale;
        }
    }

    mW = w;
    mX = x;
    mY = y;
    mZ = z;
}

Quaternion Quaternion::multiply(Quaternion a, Quaternion b) {
    return Quaternion(a.mW * b.mW - a.mX * b.mX - a.mY * b.mY - a.mZ * b.mZ,
            a.mW * b.mX + a.mX * b.mW + a.mY * b.mZ - a.mZ * b.mY,
            a.mW * b.mY + a.mY * b.mW + a.mZ * b.mX - a.mX * b.mZ,
            a.mW * b.mZ + a.mZ * b.mW + a.mX * b.mY - a.mY * b.mX);
}

Quaternion Quaternion::divide(Quaternion a, Quaternion b) {
    return (a * (b.inverse()));
}

Quaternion Quaternion::add(Quaternion a, Quaternion b) {
    return Quaternion(a.mW + b.mW,
            a.mX + b.mX,
            a.mY + b.mY,
            a.mZ + b.mZ);
}

Quaternion Quaternion::subtract(Quaternion a, Quaternion b) {
    return Quaternion(a.mW - b.mW,
            a.mX - b.mX,
            a.mY - b.mY,
            a.mZ - b.mZ);
}
