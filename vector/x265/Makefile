# Note: to build the x265 benchmarks, run:
#   CXX=/path/to/clang++ PREFIX=MY_BINARY_PREFIX_ make all

CXX ?= clang++
override CXXFLAGS += -DX265_DEPTH=8 -O3 -Isource/common

# Output directory for binaries
OUTPUT_DIR ?= execs

# Feature flags for AVX2 and AVX512 targets
FLAGS_256= -march=native -mno-avx512f -mno-avx512pf -mno-avx512er -mno-avx512cd
FLAGS_512= -march=native

all: output_dir ${PREFIX}256 ${PREFIX}512

output_dir:
	mkdir -p ${OUTPUT_DIR}

${PREFIX}256_%: %.cpp output_dir
	${CXX} -c $< ${CXXFLAGS} ${FLAGS_256} -o ${OUTPUT_DIR}/$@.o

${PREFIX}256: ${PREFIX}256_dct-sse3 ${PREFIX}256_dct-ssse3 ${PREFIX}256_dct-sse41
	${CXX} ${OUTPUT_DIR}/${PREFIX}256_*.o perf.cpp ${CXXFLAGS} -o ${OUTPUT_DIR}/$@

${PREFIX}512_%: %.cpp output_dir
	${CXX} -c $< ${CXXFLAGS} ${FLAGS_512} -o ${OUTPUT_DIR}/$@.o

${PREFIX}512: ${PREFIX}512_dct-sse3 ${PREFIX}512_dct-ssse3 ${PREFIX}512_dct-sse41
	${CXX} ${OUTPUT_DIR}/${PREFIX}512_*.o perf.cpp ${CXXFLAGS} -o ${OUTPUT_DIR}/$@

