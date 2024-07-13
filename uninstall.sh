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
