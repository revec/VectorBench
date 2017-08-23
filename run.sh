#!/bin/bash

red=`tput setaf 1`
reset=`tput sgr0`

cur_dir="$(pwd)"

if [ "$CMAKE" == "" ]; then
    CMAKE=cmake
fi
   
if [ "$COMP_BUILD" != "0" ]; then
    if [ "$COMP_BUILD_DIR" == "" ] || [ "$COMP_SRC_DIR" == "" ]; then
	echo "error : specify llvm compiler src and build directories to build llvm"
	exit
    fi
    #specify here the compiler used for building clang
    
    CCPrev=$CC
    CXXPrev=$CXX
    
    CC=/usr/bin/gcc #using the gcc that is built into the system
    CXX=/usr/bin/g++ #using the g++ that is built into the system
    
    source compiler.sh
    
    CC=$CCPrev
    CXX=$CXXPrev
    cd $cur_dir
fi

#check if the compiler is found
if ([ -f $COMP_BUILD_DIR/bin/clang ]) && ([ -f $COMP_BUILD_DIR/bin/clang++ ]); then
    export CC="$COMP_BUILD_DIR/bin/clang"
    export CXX="$COMP_BUILD_DIR/bin/clang++"
    export CLINK="$COMP_BUILD_DIR/bin/clang"
    echo "${red}clang found${reset}"
    echo $CC
    echo $CXX
    sleep 2
else
    echo "warning clang or clang++ not found not setting CC or CXX variables"
    echo $CC
    echo $CXX
    sleep 2
fi


if [ "$1" == "all" ]; then
   cd vec  
   echo "${red}running all vector benchmarks${reset}"
   ./run.sh "spec2006"
   ./run.sh "spec2017"
   ./run.sh "nas"
   cd $cur_dir
   cd revec
   echo "${red}running all revectorization benchmarks${reset}"
   ./run.sh "simd"
   cd $cur_dir
elif [ "$1" == "vec" ]; then
    cd vec
    if [ "$2" == "" ]; then
	echo "${red}running all vector benchmarks${reset}"
	./run.sh "spec2006" 
	./run.sh "spec2017"
	./run.sh "nas"
    else
	./run.sh "$2" "$3" "$4"
    fi
    cd $cur_dir
elif [ "$1" == "revec" ]; then
    cd revec
    if [ "$2" == "" ]; then
	echo "${red}running all revectorization benchmarks${reset}"
	./run.sh "simd"
    else
	./run.sh "$2" "$3"
    fi
    cd $cur_dir
fi
