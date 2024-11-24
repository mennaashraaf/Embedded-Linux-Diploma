#! /bin/bash
echo "shell scripting is fun!"
msg_var="shell scripting is fun! from var"
echo $msg_var
var1=$1
if [[ $var1 < 2 ]]; then
echo "$var1 is not a prime number"
exit 0
fi
prime_flag=1
for (( i=2; i*i<=var1; i++ )); do
 if [[ $(( var1 % i )) == 0 ]]; then
   prime_flag=0
   break
  fi
  done

if [[ $prime_flag == 1 ]];
then echo "$var1 is a prime number"
else
echo "this is not a prime number"
fi

