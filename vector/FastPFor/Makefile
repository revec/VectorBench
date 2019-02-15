CXX ?= clang++
OUTPUT_DIR ?= execs
override CXXFLAGS += -std=c++11 -O3

FLAGS_256= -march=native -mno-avx512f -mno-avx512pf -mno-avx512er -mno-avx512cd
FLAGS_512= -march=native

output_dir:
	mkdir -p ${OUTPUT_DIR}

${PREFIX}256_%.o: src/%.cpp output_dir
	${CXX} -c ${CXXFLAGS} ${FLAGS_256} $< -o ${OUTPUT_DIR}/$@ -Iheaders

${PREFIX}256_benchhorizontalbitpacking: ${PREFIX}256_horizontalbitpacking.o output_dir
	${CXX} ${CXXFLAGS} ${FLAGS_256} ${OUTPUT_DIR}/$< src/benchhorizontalbitpacking.cpp -o ${OUTPUT_DIR}/$@ -Iheaders

${PREFIX}512_%.o: src/%.cpp output_dir
	${CXX} -c ${CXXFLAGS} ${FLAGS_512} $< -o ${OUTPUT_DIR}/$@ -Iheaders

${PREFIX}512_benchhorizontalbitpacking: ${PREFIX}512_horizontalbitpacking.o output_dir
	${CXX} ${CXXFLAGS} ${FLAGS_512} ${OUTPUT_DIR}/$< src/benchhorizontalbitpacking.cpp -o ${OUTPUT_DIR}/$@ -Iheaders

all: ${PREFIX}256_benchhorizontalbitpacking ${PREFIX}512_benchhorizontalbitpacking

clean:
	rm -r ${OUTPUT_DIR}
