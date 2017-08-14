#!/bin/bash

if [ "$COMP_BUILD_DIR" == "" ] || [ "$COMP_SRC_DIR" == "" ]; then
    echo "error : specify llvm compiler src and build directories"
    exit
fi

CUR_DIR=$(pwd)

#get the repo
if !([ -d "$COMP_SRC_DIR" ]); then
    git clone git@github.mit.edu:charithm/llvm-revec.git $COMP_SRC_DIR
    cd $COMP_SRC_DIR/tools
    git clone https://github.com/llvm-mirror/clang.git
    cd clang
    git checkout -b clang-working eea8887a
else
    cd $COMP_SRC_DIR
    git pull
fi

#need the third party cplex library check for that
if !([ -d "$COMP_SRC_DIR/libraries/cplex" ]); then
    echo "please download and place cplex library in the appropriate place - check README"
    exit
fi

#go back and compile the compiler
mkdir -p $COMP_BUILD_DIR
cd $COMP_BUILD_DIR
#build the release version of the compiler
if [ "$COMP_GENERATE" != "0" ]; then
    if [ "$COMP_VERSION" != "Debug" ] || [ "$COMP_VERSION" != "Release" ]; then
	echo "warning build type not selected or wrong type; building release version"
	COMP_VERSION=Release
	sleep 10
    fi
    cmake -DLLVM_TARGETS_TO_BUILD=X86 -DC_INCLUDE_DIRS="/Library/Developer/CommandLineTools/usr/bin/../../usr/include/c++/v1:/Library/Developer/CommandLineTools/usr/bin/../../usr/include:/usr/include" -DLLVM_ENABLE_LIBCXX=ON -DLLVM_ENABLE_EH=ON -DLLVM_ENABLE_RTTI=ON -DCMAKE_BUILD_TYPE=$COMP_VERSION $COMP_SRC_DIR
fi

make -j 4 clang
if !([ -f $COMP_BUILD_DIR/bin/clang ]) || !([ -f $COMP_BUILD_DIR/bin/clang++ ]); then
    echo "clang not built successfully"
    exit
fi
