read -p "enter 4-digit number? " num

sum=0
while [ $num -gt 0 ]
do
	let remainder=num%10
    if (( remainder % 2 == 0 )); then
	    let sum=sum+remainder
    fi
	let num=num/10
done
echo -n "The sum of even digits is : "
echo $sum
