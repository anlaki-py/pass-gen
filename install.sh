#!/bin/bash

# Check if the pass executable already exists
if ! command -v pass &> /dev/null; then
    # Download the pass executable from GitHub
    if curl -sSL -o pass https://raw.githubusercontent.com/anlaki-py/pass-gen/main/pass; then
        # Make the downloaded file executable
        if chmod +x pass; then
            # Move the pass executable to a directory in your $PATH
            if sudo mv pass /usr/local/bin/; then
                echo "The pass executable has been successfully moved to the PATH."
            else
                echo "Failed to move the pass executable to /usr/local/bin/"
                exit 1
            fi
        else
            echo "Failed to make the pass file executable."
            exit 1
        fi
    else
        echo "Failed to download the pass executable."
        exit 1
    fi
else
    echo "The pass executable already exists in the PATH. Skipping download."
fi
