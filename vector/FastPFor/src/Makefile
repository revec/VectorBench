CXX_REVEC ?= /home/paras/revectorization-artifact/build-dev/bin/clang++
CXX_NO_REVEC ?= /home/paras/revectorization-artifact/build-pre-revec/bin/clang++
OUTPUT_DIR ?= execs
CXXFLAGS= -std=c++11 -O3

FLAGS_256= -march=native -mno-avx512f -mno-avx512pf -mno-avx512er -mno-avx512cd
FLAGS_512= -march=native


output_dir:
	mkdir -p ${OUTPUT_DIR}

NR256_%.o: %.cpp output_dir
	${CXX_NO_REVEC} -c ${CXXFLAGS} ${FLAGS_256} $< -o ${OUTPUT_DIR}/$@ -I../headers

NR256_benchhorizontalbitpacking: NR256_horizontalbitpacking.o output_dir
	${CXX_NO_REVEC} ${CXXFLAGS} ${FLAGS_256} ${OUTPUT_DIR}/$< benchhorizontalbitpacking.cpp -o ${OUTPUT_DIR}/$@ -I../headers

NR512_%.o: %.cpp output_dir
	${CXX_NO_REVEC} -c ${CXXFLAGS} ${FLAGS_512} $< -o ${OUTPUT_DIR}/$@ -I../headers

NR512_benchhorizontalbitpacking: NR512_horizontalbitpacking.o output_dir
	${CXX_NO_REVEC} ${CXXFLAGS} ${FLAGS_512} ${OUTPUT_DIR}/$< benchhorizontalbitpacking.cpp -o ${OUTPUT_DIR}/$@ -I../headers

R256_%.o: %.cpp output_dir
	${CXX_REVEC} -c ${CXXFLAGS} ${FLAGS_256} $< -o ${OUTPUT_DIR}/$@ -I../headers

R256_benchhorizontalbitpacking: R256_horizontalbitpacking.o output_dir
	${CXX_REVEC} ${CXXFLAGS} ${FLAGS_256} ${OUTPUT_DIR}/$< benchhorizontalbitpacking.cpp -o ${OUTPUT_DIR}/$@ -I../headers -fno-revectorize

R512_%.o: %.cpp output_dir
	${CXX_REVEC} -c ${CXXFLAGS} ${FLAGS_512} $< -o ${OUTPUT_DIR}/$@ -I../headers

R512_benchhorizontalbitpacking: R512_horizontalbitpacking.o output_dir
	${CXX_REVEC} ${CXXFLAGS} ${FLAGS_512} ${OUTPUT_DIR}/$< benchhorizontalbitpacking.cpp -o ${OUTPUT_DIR}/$@ -I../headers -fno-revectorize

all: NR256_benchhorizontalbitpacking NR512_benchhorizontalbitpacking R256_benchhorizontalbitpacking R512_benchhorizontalbitpacking

clean:
	rm -r ${OUTPUT_DIR}
