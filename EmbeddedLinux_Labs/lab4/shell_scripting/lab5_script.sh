#!/bin/bash
f_name="file1.txt"
path_var=~/
exist=0
for i in "$path_var"/* ; do
 if [[ "$i" == "$path_var/$f_name" ]] ; then
   exist=1
  fi
done
if [ $exist == 1 ]; then
   echo "$f_name exists"
  else
  echo "$f_name doesn't exist"
 fi
perm_var=$(ls -l $path_var/$f_name | grep -c "w")
if [ $perm_var == 0 ] ; then
 echo "$f_name has no write permission"
else
 echo "$f_name has write permission"
fi
