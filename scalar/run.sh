#!/bin/bash

red=`tput setaf 1`
reset=`tput sgr0`

cur_dir="$(pwd)"

action=$1
bench=$2

if [ "$3" != "" ]; then
    individual=$3
else
    individual=all
fi

#check if additional arguments are given; otherwise use defaults.
if [ "$bench" == "spec2006" ] || [ "$bench" == "spec2017" ]; then
    if [ "$4" != "" ]; then
	tune=$4
    else
	tune=peak
    fi
    if [ "$5" != "" ]; then
	size=$5
    else
	size=ref
    fi
elif [ "$bench" == "nas" ]; then
    if [ "$4" != "" ]; then
	class=$4
    else
	class=A
    fi
else
    "error: non-existent scalar benchmark"
    exit 1
fi



if [ "$bench" == "spec2006" ]; then
    echo "${red}running spec2006 benchmarks${reset}"
    cd spec2006-install
    . ./shrc
    if [ $SPEC2006_CONFIG == "" ]; then
	echo "error specify spec2006 config using env var SPEC2006_CONFIG"
	exit
    fi

    if [ "$action" == "build" ]; then
	FC1=$FC CC1=$CC CXX1=$CXX runspec --config=$SPEC2006_CONFIG --action=scrub --noreportable --tune=$tune --size=$size $individual
    fi
    FC1=$FC CC1=$CC CXX1=$CXX runspec --config=$SPEC2006_CONFIG --action=$action --noreportable --tune=$tune --size=$size $individual
    
elif [ "$bench" == "spec2017" ]; then
    echo "${red}running spec2017 benchmarks${reset}"
    cd spec2017-install
    . ./shrc
    if [ $SPEC2017_CONFIG == "" ]; then
	echo "error specify spec2017 config using env var SPEC2017_CONFIG"
	exit
    fi

    if [ "$action" == "build" ]; then
	FC1=$FC CC1=$CC CXX1=$CXX runcpu --config=$SPEC2017_CONFIG --action=scrub --noreportable --tune=$tune --size=$size $individual
    fi
    FC1=$FC CC1=$CC CXX1=$CXX runcpu --config=$SPEC2017_CONFIG --action=$action --noreportable --tune=$tune --size=$size $individual


elif [ "$bench" == "nas" ]; then
    
    echo "${red}running nas benchmarks${reset}"
    cd NPB3.0-omp-C
    mkdir -p bin


    if [ "$individual" == "all" ]; then
	nas="bt sp lu mg ft is cg ep"
    else
	nas=$individual
    fi

    
    if [ "$action" == "build" ]; then
	make clean
    fi
    
    if [ "$action" == "build" ] || [ "$action" == "run" ]; then
	for bench in $nas; do
	    CFLAGS1=$CFLAGS make $bench CLASS=$class
	done
    fi

    if [ "$action" == "run" ]; then
	for bench in $nas; do
	    ./bin/$bench.$class
	done
    fi
  
fi


cd $cur_dir
