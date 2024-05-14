#!/bin/bash

#python file path
py="$HOME/pass-gen/python/pass/pass.py"

#log file path
log="$HOME/pass-gen/python/pass/pass.log"

#help file path
help="$HOME/pass-gen/python/pass/help.txt"

if [ "$1" = "cat" ]; then
    if [ -f $log ]; then
        less $log
        exit
    else
        echo Error: File is empty or not found.
        exit
    fi
elif [ "$1" = "clear" ]; then
    if [ -f $log ]; then
        rm $log
        echo The log file has been successfully cleared.
        exit
    else
        echo Error: File is already cleared or deleted.
        exit
    fi
elif [ "$1" = "help" ]; then
    if [ -f $help ]; then
	less $help
	exit
    else
	echo Error: file not found.
        exit	
    fi
fi

    python3 $py 
