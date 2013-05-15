#!/bin/bash

targets="juncluster1 juncluster2 juncluster4"
file=$1

for i in $targets
do 
    ssh $i "mkdir -p $PWD"
done

if [ $# -lt 1 ]
then
    #for i in $targets
    #do
    #    rsync -avz --exclude '*.make' --exclude '*.cmake' $PWD/ $i:$PWD
    #done
    echo ?
else
    if [ -f $file ]
    then 
        for i in $targets
        do
            rsync -az --exclude '*.make' --exclude '*.cmake' $file $i:$PWD
        done
    else
        echo "File $1 not found."
    fi
fi
