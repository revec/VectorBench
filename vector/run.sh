#!/bin/bash

red=`tput setaf 1`
reset=`tput sgr0`

cur_dir="$(pwd)"

action=$1
bench=$2
individual=$3


if [ "$bench" == "simd" ]; then
    echo "${red}running simd benchmarks${reset}"
    cd simd

    if [ "$4" == "" ]; then # we assume a default compiler in this case
	exec="default"
    else
	exec=$4
    fi


    if [ "$action" == "build" ]; then
	EXEC=$exec make clean
    fi
    
    mkdir -p execs_$exec
    cp -r data execs_$exec/

    test_files=""
    for test_file in test/*$individual*.cpp; do
	avx2=`expr "$test_file" : '.*\(test_avx2.*\).cpp'`
	avx1=`expr "$test_file" : '.*\(test_avx1.*\).cpp'`
	sse2=`expr "$test_file" : '.*\(test_sse2.*\).cpp'`
	ssse3=`expr "$test_file" : '.*\(test_ssse3.*\).cpp'`

	file=""
	if [ "$avx2" != "" ]; then
	    file=$avx2
	elif [ "$avx1" != "" ]; then
	    file=$avx1
	elif [ "$sse2" != "" ]; then
		file=$sse2
	elif [ "$ssse3" != "" ]; then
	    file=$ssse3
	fi
	
	if [ "$file" != "" ]; then
	    test_files+=" execs_$exec/$file"
	fi
    done
    
    for test_file in $test_files; do
	EXEC=$exec make $test_file
    done

    if [ "$action" == "run" ]; then
	for test_file in $test_files; do
	    echo "running $test_file"
	    ./$test_file
	done
    fi
    
fi


cd $cur_dir
