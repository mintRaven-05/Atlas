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

sleep .5

if [ -d "$HOME/.Atlas" ]; then
  echo "removing  $HOME/.Atlas"
  rm -rf $HOME/.Atlas  
else
  echo "could not locate $HOME/.Atlas"
fi

if [ -L "/usr/bin/atlas" ]; then
  echo "removing /usr/bin/atlas"
  sudo rm /usr/bin/atlas
else
  echo "could not locate /usr/bin/atlas"
fi

if [ -d "$HOME/.local/atlas"  ]; then
  echo "removing $HOME/.local/atlas"
  rm -rf $HOME/.local/atlas
else
  echo "could not locate $HOME/.local/atlas"
fi

sleep 1

echo "Thank you for trying out Atlas."
echo "If you have any suggestions or found out any bugs, you can report it"
echo "over the issues page."
echo "Visit & follow https://www.github.com/mintRaven-05/Atlas for more projects."
