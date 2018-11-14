CXX ?= g++
CXXFLAGS += -O3 -march=native -std=c++11 -DNDEBUG
LDFLAGS += -lm -lpthread

CUR_DIR = 
SRC_DIR = source
TEST_DIR = test
INCLUDE_DIR = include $(SRC_DIR) $(TEST_DIR)
EXEC_DIR = execs_$(EXEC)

CXXFLAGS += $(addprefix -I,$(INCLUDE_DIR)) 

#each test will have its file <src_dir>/<arch>_<name>.cpp and <test_dir>/test_<arch>_<name>.cpp file which will be compiled to .o with the same name
#other files will be compiled using its own conventions
#there should be targets for test_<arch>_<name>
#python script will first compiler <arch>_<name>.cpp files and record the compilation success
#based on the compilation success it will compile and run the tests and give out a final score

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)

COMMON_SRC_FILES = $(patsubst $(SRC_DIR)/%,%,$(filter $(SRC_DIR)/base_%.cpp, $(SRC_FILES)))
COMMON_TEST_FILES = $(patsubst $(TEST_DIR)/%,%,$(filter $(TEST_DIR)/Test%.cpp,$(TEST_FILES)))

COMMON_FILES = $(COMMON_SRC_FILES) $(COMMON_TEST_FILES)

COMMON_OBJS =  $(patsubst %.cpp,$(EXEC_DIR)/%.o,$(COMMON_FILES))

#suffixed file compilation
$(EXEC_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) $^ -o $@

$(EXEC_DIR)/%.o : $(TEST_DIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) $^ -o $@

#some target specific rules
$(EXEC_DIR)/test_sse2_bgrtogray : $(EXEC_DIR)/test_sse2_bgrtogray.o $(COMMON_OBJS) $(EXEC_DIR)/sse2_bgrtogray.o $(EXEC_DIR)/sse2_bgratogray.o
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@
$(EXEC_DIR)/test_ssse3_bgratoyuv : $(EXEC_DIR)/test_ssse3_bgratoyuv.o $(COMMON_OBJS) $(EXEC_DIR)/ssse3_bgratoyuv.o $(EXEC_DIR)/sse2_bgratoyuv.o
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@
$(EXEC_DIR)/test_avx2_neural : $(EXEC_DIR)/test_avx2_neural.o $(COMMON_OBJS) $(EXEC_DIR)/avx2_neural.o $(EXEC_DIR)/sse2_neural.o
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@


#main target compilation
$(EXEC_DIR)/test_% : $(EXEC_DIR)/test_%.o $(COMMON_OBJS) $(EXEC_DIR)/%.o 
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

.PHONY: clean all
.PRECIOUS: %.o
.SECONDARY:
all:
clean:
	rm -rf $(EXEC_DIR)/*

