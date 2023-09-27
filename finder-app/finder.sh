#!/bin/sh
filesdir=$1
searchstr=$2
if [ -z "${filesdir}" ] || [ -z "${searchstr}" ]; then
    echo "Please enter both arguments"
    exit 1 #case of failure

fi
if ! [ -d "${filesdir}" ]; then
    echo "${filesdir} is not a directory"
    exit 1
fi

cd $filesdir
X=$(ls | wc -l)
Y=$(grep -r "$searchstr" | wc -l)
echo "The number of files are ${X} and the number of matching lines are ${Y}"
