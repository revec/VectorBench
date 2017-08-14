#!/bin/bash

#moves the files so that their filenames have <arch>_<name>.cpp format from Simd* format. The files
#should be in the folder already. 

O="$(ls *.cpp)"
N="$(ls *.cpp | sed 's/Simd\([A-Z][a-z0-9][a-z0-9]*\)\(.*\)/\L\1_\2/g')"

old_names=($O)
new_names=($N)

for index in ${!old_names[*]}; do 
  mv ${old_names[$index]} ${new_names[$index]}
done
