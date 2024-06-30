#!/bin/bash

# Download the pass executable from GitHub
curl -sSL -o pass https://raw.githubusercontent.com/anlaki-py/pass-gen/main/pass

# Make the downloaded file executable
chmod +x pass

# Move the pass executable to a directory in your $PATH
mv pass /usr/local/bin/

echo "The pass executable has been successfully moved to the $PATH."