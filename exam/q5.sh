#!/bin/bash

read -p "Enter your number? " num


for (( i = 0; i < num; i++ )) do
    echo -n " _"
done
echo " "

for (( j = num; j > 0; j-- )) do
    for (( i = 0; i < j; i++ )) do
        echo -n "|_"
    done
    echo "|"
done
