#!/bin/bash

#creates a test file for each src file

cur=$(pwd)
cd ../src/Simd

N="$(ls *.cpp | sed 's/Simd\([A-Z][a-z0-9][a-z0-9]*\)\(.*\)/\Ltest_\1_\2/g')"
names=($N)

cd ../../test

for index in ${!names[*]}; do 
  touch ${names[$index]}
done
