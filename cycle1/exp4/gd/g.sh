#!/bin/bash
if [[ $# != 1 ]] ; then 
	echo "Usage $0 <filename> " 
	exit
elif [[ ! -f $1 ]] ; then 
	echo "File does not exist " 
	exit
fi


while read -r line ; do 
echo $line | sed 's/a/A/g' | sed 's/e/E/g' | sed 's/i/I/g' | sed 's/o/O/g' | sed 's/u/U/g' |tee -a  outputfile.txt
done < "$1"
