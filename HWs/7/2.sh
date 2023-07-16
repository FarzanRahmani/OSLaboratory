#!/bin/bash 
a=$1
b=$2
echo "Choose the operator you want: "
echo "+ for Addition"
echo "- for Subtraction"
echo ". for Multiplication"
echo "/ for Division"
read -p "Enter your operator (+,-,.,/)\n" operator
echo " "
case $operator in
+) 
result=$(($a + $b))
echo "Sum of two numbers is: $result"
;;
-)
result=$(($a - $b))
echo "Subtraction of numbers is: $result"
;;
.)
result=$(($a * $b))
echo "Multiplication of numbers is: $result"
;;
/)
result=$(($a / $b))
echo "The division of numbers is: $result"
;;
*)
echo "Invalid Choice"
esac
