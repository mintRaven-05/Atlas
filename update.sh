#!/bin/bash

if [[ "$(grep "VERSION" $HOME/.local/atlas/VERSION | cut -c 10-)" == "$(curl -s https://api.github.com/repos/mintRaven-05/Atlas/releases/latest | grep tag_name | cut -c 16-21)" ]]; then
    echo "no updates released !"
else
    echo "A new version of atlas is released"
    read -p "Do you want to install the update [y/N]: " choice
    choice=${choice,,}
    if [[ $choice == "" || $choice == "n" || $choice == "no" ]]; then
        echo "Aborting update ..."
    elif [[ $choice == "y" || $choice == "yes" || $choice == "ye" ]]; then
        echo "Downloading latest update"
        
        if [ -d "$HOME/Atlas" ]; then
            rm -rf $HOME/Atlas
            git clone https://github.com/mintRaven-05/Atlas.git $HOME/Atlas

            sleep .3
            echo "latest release downloaded successfully !"
            echo "removing current version"
            sleep .3
            
            $HOME/.Atlas/uninstall.sh
    
            sleep 2
            clear
            sleep .3
            
            
            cd $HOME/Atlas
            chmod +x ./install.sh
            ./install.sh
        else
            git clone https://github.com/mintRaven-05/Atlas.git $HOME/Atlas
            echo "press enter to continue"
            sleep .3
            echo "latest release downloaded successfully !"
            echo "removing atlas $(atlas -v | grep v | cut -c 33-)"
            sleep .3

            $HOME/.Atlas/uninstall.sh

            sleep 2
            clear
            sleep .3


            cd $HOME/Atlas
            chmod +x ./install.sh
            ./install.sh
        fi

    fi

fi

