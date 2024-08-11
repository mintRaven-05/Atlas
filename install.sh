#!/bin/bash

echo "   _____     __   .__                   "
echo "  /  _  \  _/  |_ |  |  _____     ______"
echo " /  /_\  \ \   __\|  |  \__  \   /  ___/"
echo "/    |    \ |  |  |  |__ / __ \_ \___ \ "
echo "\____|__  / |__|  |____/(____  //____  >"
echo "        \/                   \/      \/ "
echo ""
echo "Copyright (C) 2024, Debjeet Banerjee"
echo ""
chmod +x uninstall.sh
chmod +x update.sh

if [ -f "/usr/bin/curl" ]; then
    echo ""
else
    echo "install curl using your package manager after installation"
    echo "The update feature will not work if curl is not installed"
fi

sleep 2.5

echo "preparing files for installation"
if [ -d "$HOME/.local/atlas"  ];then
    cp update.sh $HOME/.local/atlas
    cp VERSION $HOME/.local/atlas
else
    mkdir $HOME/.local/atlas
    cp update.sh $HOME/.local/atlas
    cp VERSION $HOME/.local/atlas
fi

sleep .5
make all

echo "creating $HOME/.Atlas"
mkdir $HOME/.Atlas

echo "creating uninstaller at $HOME/.Atlas"
cp uninstall.sh $HOME/.Atlas

echo "creating backup folder at $HOME/.Atlas/backup"
mkdir $HOME/.Atlas/backup
for file in *; do
    if [ -f "$file" ]; then
        cp $file $HOME/.Atlas/backup
        echo "copying $file to $HOME/.Atlas/backup"
        sleep .3
    elif [ -d "$file" ]; then
        cp -r $file $HOME/.Atlas/backup
        echo "copying ./$file to $HOME/.Atlas/backup"
    else
        echo "unexpected error caused while installation!"
        exit 1
    fi
done

sleep .5

echo "creating symlink for atlas"
sudo ln -s $HOME/.Atlas/backup/atlas /usr/bin/atlas

echo "cleaning up"
make clean

sleep 1.5
echo ""
echo "installation completed"
echo "you can test your installation by running atlas --version"
echo "to uninstall, go to $HOME/.Atlas and run sudo uninstall.sh"
echo "follow me on https://www.github.com/mintRaven-05 for more projects"
