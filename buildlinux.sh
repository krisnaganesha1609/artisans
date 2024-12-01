#!/bin/bash

# Set build variables
PWDDIR=`pwd`
GPPPATH=`command -v g++`

# check if previous version of main exist
if [ -f $PWDDIR/build/main ];
    then
        echo "cleaning up..."
        rm $PWDDIR/build/main
fi

# check if g++ exist
if [ "$GPPPATH" == "" ];
    then
        echo "g++ is not installed. Search and install it with your distro Package Manager first before executing this script."
        exit 1
fi

# build the main program
echo "Building..."
g++ main.cpp -o $PWDDIR/build/main
