#!/bin/bash
#echo "please enter name of file or directory "
#read f_name
#f_name=$1
for f_name in "$@" ; do
if [ -d $f_name ]; then
  l_var=$(ls -ld "./$f_name")
 echo "$f_name is a directory with contents: "
 echo "$l_var"
elif [ -f $f_name ]; then
 echo "$f_name is a regular file"
else
 echo "$f_name doesn't exist"
fi
done


