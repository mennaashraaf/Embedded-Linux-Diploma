#!/bin/bash
file_count() {
nfiles=$(ls -1 | wc -l)
echo "number of files in current directory is: $nfiles"
}

file_count 
