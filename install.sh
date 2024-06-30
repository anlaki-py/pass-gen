#!/bin/bash

set -e

curl -sSL -o pass https://raw.githubusercontent.com/anlaki-py/pass-gen/main/pass
sudo chmod +x pass
sudo mv pass /usr/local/bin/

echo "The pass executable has been successfully moved to the PATH."
