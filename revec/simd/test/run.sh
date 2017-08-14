#!/bin/bash

CUR=$(pwd)
cd ../source/
rm *.o
g++ -c -O3 -mavx2 -std=c++11 -DNDEBUG -I. base_*.cpp
g++ -c -O3 -mavx2 -std=c++11 -DNDEBUG -I. sse2_yuvtobgra.cpp 
cd ../test/
rm *.o
g++ -c -O3 -mavx2 -std=c++11 -I. -I../source -DNDEBUG test_sse2_yuvtobgra.cpp TestData.cpp TestLog.cpp TestPerformance.cpp TestUtils.cpp
g++ -O3 -mavx2 test_sse2_yuvtobgra.o TestData.o TestLog.o TestPerformance.o TestUtils.o ../source/*.o -lpthread -o Testoutput
cd ${CUR}
