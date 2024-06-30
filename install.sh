#!/bin/bash

set -e

# Function to remove pass file
remove_pass_file() {
    rm -f /usr/local/bin/pass
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

# Remove existing pass file if it exists
if [ -f /usr/local/bin/pass ]; then
    echo "The pass file already exists. Removing it..."
    remove_pass_file
fi

# Install new pass file
install_pass_file
