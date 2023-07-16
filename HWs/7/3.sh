read -sp 'Password: ' password 
echo " "
if [ $password -eq "123456" ];
then
echo "Welcome"
else
echo "Wrong Password"
fi