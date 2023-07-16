#!/bin/bash 
if (($1 > $2))  # [$1 -gt $2]
then
    echo "first number ($1) is bigger"
elif (($2 > $1)) # [$1 -lt $2]
then
    echo "second number ($2) is bigger"
else
    echo "numbers were equal ($1)"
fi
