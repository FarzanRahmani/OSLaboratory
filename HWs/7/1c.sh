sum=0 
diff=$1-$2
cnt=0
for ((i=$1 + 1; i<$2; i++)) 
do
    sum=$(($sum+i))
    cnt=$(($cnt+1))    
done
if (($diff == 0)) 
then
    echo "There isn't any number between $1 and $2"
else
    echo $(($sum / $cnt))
fi