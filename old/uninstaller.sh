#!/bin/bash

passfile="/usr/local/bin/pass" # install location
passgen="$HOME/pass-gen" # programe folder
removed=false

if [ -f "$passfile" ]; then
    sudo rm "$passfile"
    echo "Removed $passfile."
    removed=true
else
    echo "Error: '$passfile' does not exist."
fi

# Warn the user, since the script is inside the directory it tries to delete.
if [ -d "$passgen" ]; then
    echo "Warning: This script will delete itself along with the directory $passgen."
    echo "and you might not see the final messages."
    read -p "Proceed with deleting $passgen? (Y/n): " confirm
    if [[ $confirm =~ ^[Yy]$ ]]; then
        sudo rm -rf "$passgen"
        echo "Removed $passgen."
        removed=true
    else
        echo "Aborted deletion of $passgen."
    fi
else
    echo "Error: '$passgen' does not exist."
fi

if [ "$removed" = true ]; then
    echo "Successfully uninstalled necessary files."
else
    echo "No files were uninstalled."
fi

# Since the script deletes its directory, you might not see the final messages.
