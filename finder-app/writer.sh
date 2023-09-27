#!/bin/sh
writefile=$1
writestr=$2
if [ -z "${writefile}" ] || [ -z "${writestr}" ]; then
    echo "Please enter both arguments"
    exit 1 #case of failure
fi
#echo ${writestr} > ${writefile}

mkdir -p $(dirname ${writefile})

touch $writefile
if [ $? -ne 0 ];then
    echo "Failed to create the file"
    exit 1 
fi

echo "$writestr" > "$writefile" || { echo "Failed to write the file"; exit 1; }