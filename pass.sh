#!/bin/bash

#python code path
py="python/pass/pass.py"

#log file path
log="python/pass/pass.txt"

if [ "$1" = "cat" ]; then
    if [ -f $log ]; then
        cat $log
        exit
    else
        echo "Error: File is empty."
        exit
    fi
elif [ "$1" = "clear" ]; then
    if [ -f $log ]; then
        rm $log
        echo "=> The log file has been successfully cleared."
        exit
    else
        echo "Error: File is already cleared."
        exit
    fi
fi
    python3 $py 