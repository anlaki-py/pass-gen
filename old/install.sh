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
    echo "Choose an option:"
    echo "1. Cancel (keep the current installed one)"
    echo "2. Uninstall (remove and exit)"
    echo "3. Update (remove and download/install again)"
    read -p "Enter your choice (1/2/3): " choice </dev/tty
    case "$choice" in 
        1 ) echo "Keeping the current installed pass file. Exiting."; exit 0;;
        2 ) remove_pass_file; echo "Uninstallation complete. Exiting."; exit 0;;
        3 ) remove_pass_file; echo "Proceeding with update...";;
        * ) echo "Invalid choice. Exiting."; exit 1;;
    esac
fi

# Install new pass file
install_pass_file
