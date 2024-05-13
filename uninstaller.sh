#!/bin/bash

passfile="/usr/bin/pass"

if [ ! -f "$passfile" ]; then
    echo "Error: '$passfile' does not exist."
    exit
else
    sudo rm "$passfile" 
fi

echo "Successfully uninstalled $passfile"
