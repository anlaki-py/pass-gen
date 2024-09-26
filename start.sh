#!/bin/bash

set -e

INSTALL_DIR="/usr/local/bin"  # Specify the installation directory

# Check if the program is already installed
if [ -f "$INSTALL_DIR/pass" ]; then
    echo "The program 'pass' is already installed."
    read -r -p "Do you want to 
(1) cancel installation.
(2) replace it. 
(3) uninstall? 
» " choice

    case "$choice" in
        1)
            echo "Installation canceled."
            exit 0
            ;;
        2)
            echo "Replacing the existing installation..."
            ;;
        3)
            echo "Uninstalling..."
            if [[ $EUID -eq 0 ]]; then
                rm "$INSTALL_DIR/pass"
            else
                sudo rm "$INSTALL_DIR/pass"
            fi
            echo "Uninstallation successful."
            exit 0
            ;;
        *)
            echo "Invalid choice. Installation canceled."
            exit 1
            ;;
    esac
fi

# Compile the program
g++ -o pass src/pass.cpp

if [ $? -eq 0 ]; then
    # Install the program
    if [[ $EUID -eq 0 ]]; then
        mv pass "$INSTALL_DIR/pass"
        chmod +x "$INSTALL_DIR/pass"  # Make it executable
    else
        sudo mv pass "$INSTALL_DIR/pass"
        sudo chmod +x "$INSTALL_DIR/pass"  # Make it executable
    fi
    echo "Installation successful! Try 'pass -h' to show help."
else
    echo "Compilation failed!"
    exit 1
fi