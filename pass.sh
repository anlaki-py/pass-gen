#!/bin/bash

#python file path
py="python/pass/pass.py"

#log file path
log="python/pass/pass.txt"

if [ "$1" = "cat" ]; then
    if [ -f $log ]; then
        cat $log
        exit
    else
        echo "Error: File is empty or not found."
        exit
    fi
elif [ "$1" = "clear" ]; then
    if [ -f $log ]; then
        rm $log
        echo "=> The log file has been successfully cleared."
        exit
    else
        echo "Error: File is already cleared or deleted."
        exit
    fi
fi
    python3 $py 
