CXX_REVEC ?= /mnt/revec/build/bin/clang++
CXX_NOREVEC ?= /mnt/revec/build-pre-revec/bin/clang++
OUTPUT_DIR ?= execs
FLAGS_256= -march=skylake
FLAGS_512= -march=native

CXXFLAGS= -DX265_DEPTH=8 -O3 -Isource/common

all: output_dir NR256 NR512 R256 R512

output_dir:
	mkdir -p ${OUTPUT_DIR}

#NR256_%.o: %.cpp output_dir:
#	${CXX_NOREVEC} -c $< ${CXXFLAGS} ${FLAGS_256} -o ${OUTPUT_DIR}/$@

NR256_%: %.cpp output_dir
	${CXX_NOREVEC} -c $< ${CXXFLAGS} ${FLAGS_256} -o ${OUTPUT_DIR}/$@.o

NR256: NR256_dct-sse3 NR256_dct-ssse3 NR256_dct-sse41
	${CXX_NOREVEC} ${OUTPUT_DIR}/NR256_*.o perf.cpp ${CXXFLAGS} -o ${OUTPUT_DIR}/$@

NR512_%: %.cpp output_dir
	${CXX_NOREVEC} -c $< ${CXXFLAGS} ${FLAGS_512} -o ${OUTPUT_DIR}/$@.o

NR512: NR512_dct-sse3 NR512_dct-ssse3 NR512_dct-sse41
	${CXX_NOREVEC} ${OUTPUT_DIR}/NR512_*.o perf.cpp ${CXXFLAGS} -o ${OUTPUT_DIR}/$@

R256_%: %.cpp output_dir
	${CXX_REVEC} -c $< ${CXXFLAGS} ${FLAGS_256} -o ${OUTPUT_DIR}/$@.o

R256: R256_dct-sse3 R256_dct-ssse3 R256_dct-sse41
	${CXX_REVEC} ${OUTPUT_DIR}/R256_*.o perf.cpp ${CXXFLAGS} -o ${OUTPUT_DIR}/$@

R512_%: %.cpp output_dir
	${CXX_REVEC} -c $< ${CXXFLAGS} ${FLAGS_512} -o ${OUTPUT_DIR}/$@.o

R512: R512_dct-sse3 R512_dct-ssse3 R512_dct-sse41
	${CXX_REVEC} ${OUTPUT_DIR}/R512_*.o perf.cpp ${CXXFLAGS} -o ${OUTPUT_DIR}/$@


#run_R256_%: R256_%
#	./${OUTPUT_DIR}/$<


#dct-sse3-NR256:
#	${CXX_PRE_REVEC} -c dct-sse3.cpp ${CFLAGS} -march=skylake -o dct-sse3-NR256.o
#	${CXX_REVEC} dct-sse3-NR256.o perf.cpp -o NR256 ${CFLAGS}
#
#dct-sse3-R256:
#	${CXX_REVEC} -c dct-sse3.cpp ${CFLAGS} -march=skylake -o dct-sse3-R256.o -mllvm -write-revec-tree
#	${CXX_REVEC} dct-sse3-R256.o perf.cpp -o R256 ${CFLAGS}
