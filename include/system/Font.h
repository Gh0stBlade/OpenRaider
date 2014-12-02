/*!
 * \file include/Font.h
 * \brief Font interface
 *
 * \author xythobuz
 */

#ifndef _FONT_H_
#define _FONT_H_

#include <string>

/*!
 * \brief Font interface
 */
class Font {
  public:
    static void shutdown();

    static int initialize(std::string font = "");

    static std::string getFontName() { return fontName; }

    static unsigned int widthText(float scale, std::string s);

    static unsigned int heightText(float scale, unsigned int maxWidth, std::string s);

    static void drawText(unsigned int x, unsigned int y, float scale,
                         const unsigned char color[4], std::string s);

    static void drawTextWrapped(unsigned int x, unsigned int y, float scale,
                                const unsigned char color[4], unsigned int maxWidth, std::string s);

    static void drawTextCentered(unsigned int x, unsigned int y, float scale,
                                 const unsigned char color[4], unsigned int width, std::string s);

  private:
    static bool isInit;
    static std::string fontName;
};

#endif
