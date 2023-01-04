#!/bin/bash

if [ $1 == 'S' ]; then
    rm *.s 
elif [ $1 == 'target' ]; then
    rm target
else
    rm *.s target
fi
