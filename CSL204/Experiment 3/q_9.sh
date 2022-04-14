#! /bin/bash

if [ $# -lt 3 ]
then 
    echo "Enter three file names"
else
    echo -ne "" > $3

    let i=0
    while  IFS='\n' read -r line 
    do
        if [ $i -eq 10 ]
        then
            break
        fi
        echo $line >> "$3"
        let "i=$i+1"
    done < $1

    let i=0
    while  IFS='\n' read -r line 
    do
        if [ $i -eq 10 ]
        then
            break
        fi
        echo $line >> "$3"
        let "i=$i+1"
    done < $2

fi
