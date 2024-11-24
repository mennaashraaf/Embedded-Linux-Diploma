#!/bin/bash
f_name=$1

# Check if it's a directory
if [ -d "./$f_name" ]; then
  echo "$f_name is a directory"
  exit 1
# Check if it's a regular file
elif [ -f "./$f_name" ]; then
  echo "$f_name is a regular file"
# Check if it exists and is another type of file
elif [ -e "./$f_name" ]; then
  echo "$f_name is another type of file"
  exit 2
# If it doesn't exist
else
  echo "$f_name doesn't exist"
  exit 3
fi

