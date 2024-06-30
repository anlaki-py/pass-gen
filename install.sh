#!/bin/bash

set -e

# Function to remove pass file
remove_pass_file() {
    rm -f /usr/local/bin/pass
    echo "The pass executable has been successfully removed from the PATH."
}

# Function to download and install the pass file
install_pass_file() {
    echo "Downloading new pass file..."
    curl -sSL -o pass https://raw.githubusercontent.com/anlaki-py/pass-gen/main/pass
    chmod +x pass
    mv pass /usr/local/bin/
    echo "The pass executable has been successfully moved to the PATH."
}

# Check if pass file exists in the PATH
if [ -f /usr/local/bin/pass ]; then
    echo "The pass file already exists in /usr/local/bin."
    read -p "Do you want to uninstall it? (y/n) " choice </dev/tty
    case "$choice" in 
        y|Y ) remove_pass_file;;
        n|N ) echo "Removing the existing file and installing a new one."
              remove_pass_file;;
        * ) echo "Invalid choice. Exiting."; exit 1;;
    esac
fi

# Install new pass file
install_pass_file
