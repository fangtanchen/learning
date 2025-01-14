#!/bin/bash

SUCCESS=0
E_NOARGS=65

if [ -z "$1" ]
then
	echo "usage: `basename $0` rpm-file"
fi

{
	echo
	echo "Archive Description:"
	rpm -qpi $1
	echo
	echo "Archive Listing:"
	rpm -qpl $1
	echo
	rpm -i --test $1
	if [ "$?" -eq $SUCCESS ]
	then
		echo "$1 can be installed."
	else
		echo "$1 cannot be installed."
	fi
	echo	
} > "$1.test"

echo "Results of rpm test in file $1.test"
exit 0
