#!/bin/bash

ping -c 2 $1

if [ $? == 0 ] 
then
  echo "Done"
else 
  echo "The address is unreachable"
fi

