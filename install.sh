#!/bin/bash

set -e

# Function to remove pass file
remove_pass_file() {
    rm /usr/local/bin/pass
    echo "Existing pass file removed."
}

# Function to download and install the pass file
install_pass_file() {
    echo "Downloading new pass file..."
    curl -sSL -o pass https://raw.githubusercontent.com/anlaki-py/pass-gen/main/pass
    chmod +x pass
    mv pass /usr/local/bin/
    echo "The pass executable has been successfully moved to the PATH."
}

if [ -f /usr/local/bin/pass ]; then
    read -p "The pass file already exists. Do you want to remove it? (y/n): " choice
    case "$choice" in 
      y|Y ) remove_pass_file
            install_pass_file;;
      n|N ) echo "Existing pass file retained. Exiting script."
            exit 0;;
      * ) echo "Invalid input. Exiting script."
          exit 1;;
    esac
else
    install_pass_file
fi
