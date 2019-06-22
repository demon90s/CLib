#! /bin/bash

if [ "$1" = "" ]; then
	echo "no input file"
	exit 1
fi

tr -d "\015" < $1 > $1.bak
mv $1.bak $1
