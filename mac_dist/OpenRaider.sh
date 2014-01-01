#!/bin/sh
cd `dirname $0`
if [ ! -d "${HOME}/.OpenRaider" ]; then
    echo "Setting up OpenRaider for user $USER..."
    mkdir -p ~/.OpenRaider
    cp ../Resources/defaults/OpenRaider.init ~/.OpenRaider/
    cp ../Resources/defaults/custom.cfg ~/.OpenRaider/
    mkdir -p ~/.OpenRaider/paks
    mkdir -p ~/.OpenRaider/music
    mkdir -p ~/.OpenRaider/data
    mkdir -p ~/.OpenRaider/sshots
    cp ../Resources/defaults/*.tga ~/.OpenRaider/data
    cp ../Resources/defaults/*.wav ~/.OpenRaider/data
    cp ../Resources/defaults/*.ttf ~/.OpenRaider/data
    echo "DONE"
    osascript -e 'tell app "System Events" to display alert "Initial Configuration stored in ~/.OpenRaider\n\nView and edit OpenRaider.init to your needs..."'
fi
if [[ ! -n `find "${HOME}/.OpenRaider/paks" -type f -exec echo Found {} \;` ]]; then
    echo "Missing level files!"
    osascript -e 'tell app "System Events" to display alert "No level files stored in ~/.OpenRaider/paks\n\nPlace level files there and edit ~/.OpenRaider/OpenRaider.init"'
else
    if [[ ! `diff "${HOME}/.OpenRaider/OpenRaider.init" "../Resources/defaults/OpenRaider.init"` ]]; then
        if [[ ! `diff "${HOME}/.OpenRaider/custom.cfg" "../Resources/defaults/custom.cfg"` ]]; then
            echo "Unconfigured user!"
            osascript -e 'tell app "System Events" to display alert "Please edit ~/.OpenRaider/OpenRaider.init or ~/.OpenRaider/custom.cfg"'
        else
            ./OpenRaider-bin
        fi
    else
        ./OpenRaider-bin
    fi
fi