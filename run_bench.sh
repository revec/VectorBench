#!/bin/bash

red=`tput setaf 1`
reset=`tput sgr0`

cur_dir="$(pwd)"

if [ "$CMAKE" == "" ]; then
    CMAKE=cmake
fi

action=$1
suite=$2
bench=$3
individual=$4

if [ "$suite" == "all" ]; then
   cd scalar  
   echo "${red}running all scalar benchmarks${reset}"
   ./run.sh $action "spec2006"
   ./run.sh $action "spec2017"
   ./run.sh $action "nas"
   cd $cur_dir
   cd vector
   echo "${red}running all vector benchmarks${reset}"
   ./run.sh $action "simd"
   cd $cur_dir
   
elif [ "$suite" == "scalar" ]; then
    cd scalar
    if [ "$bench" == "" ]; then
	echo "${red}running all scalar benchmarks${reset}"
	./run.sh $action "spec2006" 
	./run.sh $action "spec2017"
	./run.sh $action "nas"
    else
	./run.sh $action "$bench" "$individual" "$5" "$6"
    fi
    cd $cur_dir
    
elif [ "$suite" == "vector" ]; then
    cd vector
    if [ "$bench" == "" ]; then
	echo "${red}running all vector benchmarks${reset}"
	./run.sh $action "simd"
    else
	./run.sh $action "$bench" "$individual" "$5" "$6"
    fi
    cd $cur_dir
fi
