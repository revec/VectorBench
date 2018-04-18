#!/bin/bash

red=`tput setaf 1`
reset=`tput sgr0`

#spec2006 benchmarks

spec2006bench="deal milc namd soplex povray lbm sphinx"
spec2017bench="508.namd 510.parest 511.povray 519.lbm 538.imagick 544.nab"
#add 500.perl to this - clang fails :(
nas="bt sp lu mg ft is cg ep"

cur_dir="$(pwd)"


if [ "$1" == "spec2006" ]; then
    echo "${red}running spec2006 benchmarks${reset}"
    cd spec2006-install
    . ./shrc
    if [ $SPEC2006_CONFIG == "" ]; then
	echo "error specify spec2006 config using env var SPEC2006_CONFIG"
	exit
    fi
    if [ "$3" == "" ]; then #if you don't specify a benchmark then we will run all as a reportable run
	CC1=$CC CXX1=$CXX runspec --config=$SPEC2006_CONFIG --action=scrub --tune=peak all
	for bench in $spec2006bench; do
	    CC1=$CC CXX1=$CXX runspec --config=$SPEC2006_CONFIG --action=run --noreportable --tune=peak --size=ref $bench
	done
    else
	CC1=$CC CXX1=$CXX runspec --config=$SPEC2006_CONFIG --action=scrub --tune=peak $3
	if [ "$4" != "0" ]; then
	    CC1=$CC CXX1=$CXX runspec --config=$SPEC2006_CONFIG --action=run --noreportable --tune=peak --size=$2 $3
	fi
    fi
    
elif [ "$1" == "spec2017" ]; then
    echo "${red}running spec2017 benchmarks${reset}"
    cd spec2017-install
    . ./shrc
    if [ $SPEC2017_CONFIG == "" ]; then
	echo "error specify spec2017 config using env var SPEC2017_CONFIG"
	exit
    fi
    if [ "$3" == "" ]; then #if you don't specify a benchmark then we will run all as a reportable run
	CC1=$CC CXX1=$CXX runcpu --config=$SPEC2017_CONFIG --action=scrub --tune=peak all
	for bench in $spec2017bench; do
	    CC1=$CC CXX1=$CXX runcpu --config=$SPEC2017_CONFIG --action=build --noreportable --size=ref --tune=peak $bench
	done 
	for bench in $spec2017bench; do
	    CC1=$CC CXX1=$CXX runcpu --config=$SPEC2017_CONFIG --action=run --noreportable --size=ref --tune=peak $bench
	done
    else
	CC1=$CC CXX1=$CXX runcpu --config=$SPEC2017_CONFIG --action=scrub --tune=peak $3
	if [ "$4" != "0" ]; then 
	    CC1=$CC CXX1=$CXX runcpu --config=$SPEC2017_CONFIG --action=run --noreportable --tune=peak --size=$2 $3
	fi
    fi


elif [ "$1" == "nas" ]; then
    echo "${red}running nas benchmarks${reset}"
    cd NPB3.0-omp-C
    mkdir -p bin
    make clean
    if [ "$3" == "" ]; then #we are running class A benchmarks
	CLASS=A
    else
	CLASS=$3
    fi
    if [ "$2" == "" ]; then
	for bench in $nas; do
	    CFLAGS1=$CFLAGS make $bench CLASS=$CLASS
	done
	for bench in $nas; do
	    ./bin/$bench.$CLASS
	done
    else
	CFLAGS1=$CFLAGS make $2 CLASS=$CLASS
	if [ "$4" != "0" ]; then
	    ./bin/$2.$CLASS
	fi
    fi
fi


cd $cur_dir
