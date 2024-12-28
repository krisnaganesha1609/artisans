#!/bin/bash

# Set build variables
PWDDIR=`pwd`
GPPPATH=`command -v g++`
GPPVER=`g++ --version | grep g++ | awk '{print $3}'`
MACHINEVER=`g++ -dumpmachine`
TEEPATH=`command -v tee`

# check if build directory exist
if [ ! -d $PWDDIR/build ];
    then
        echo "creating directory..."
        mkdir $PWDDIR/build
fi

# check if previous version of main exist
if [ -f $PWDDIR/build/main ];
    then
        echo "cleaning up..."
        rm -rf $PWDDIR/build/*
fi

# check if g++ exist
if [ "$GPPPATH" == "" ];
    then
        echo "g++ is not installed. Search and install it with your distro Package Manager first before executing this script."
        exit 1
fi

# check if tee exist
if [ "$TEEPATH" == "" ];
    then
        echo "tee is not installed. Search and install it with your distro Package Manager first before executing this script."
        exit 1
fi

# build the main program
echo "Building with GCC $GPPVER (g++) for $MACHINEVER..."
g++ main.cpp -o $PWDDIR/build/main 2>&1 | tee $PWDDIR/build/build.log

# Check if program builded successfully
if [ -f $PWDDIR/build/main ];
    then
        echo "Build completed successfully. The executable is located in the build directory."
    else
        echo "Build failed. Check build.log located in the build directory for more details."
fi
