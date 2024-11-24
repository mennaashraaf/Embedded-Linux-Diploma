#!/bin/bash
cat /etc/shadow
if [[ $? == 0 ]]; then
 echo "command succeeded "
else
 echo "command failed "
 exit 1
fi
