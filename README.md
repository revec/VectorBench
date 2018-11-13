# Benchmarks

This repository contains a conglomerate of benchmarks that you can use to evaluate the efficacy of your compiler transformations.
They can be used for both correctness testing as well as for performance testing of general purpose compiler transformations.
None of the benchmark code is written by us, but are extracted from popular code bases or benchmark suites that are available.
We provide you with convenience scripts and drivers to build and benchmark performance on your computer environments.
The main purpose of this repo is to provide a single source of compiler benchmarks for compiler researchers to evaluate their compiler transformations.

Redistributable code and benchmarks are included in this repo, where as benchmarks which require commercial licenses should be
downloaded and installed at the correct locations to use the drivers provided by this repo.
Benchmarks are mainly divided into two categories, namely scalar (non hand-vectorized) and vector (hand-vectorized) benchmarks.

## scalar benchmarks

1. SPEC2006 - Purchase [(link)](https://www.spec.org/cpu2006/) and install at scalar/spec2006-install
2. SPEC2017 - Purchase [(link)](https://www.spec.org/cpu2017/) and install at scalar/spec2017-install
3. NAS - C port of NAS Parallel Benchmarks [(link)](https://github.com/benchmark-subsetting/NPB3.0-omp-C) included under scalar/NPB3.0-omp-C

## vector benchmarks

1. Simd library - image processing and stencil benchmarks ([link])(https://github.com/ermig1979/Simd) included under vector/Simd. We have seperated testing of each kernel
into its own file. The kernels remain unmodified from the original benchmark suite.
2. x265 - contains kernels extracted from x265 encoding and decoding library ([link])(https://bitbucket.org/multicoreware/x265/wiki/Home) included under vector/x265
3. FastPFor - contains kernels from the popular integer packing library ([link])(https://github.com/lemire/FastPFor) included under vector/FastPFor

# Building and running benchmarks

Use the convenience script run_bench.sh to build and/or run any benchmark of your choosing or entire suites.
You need to set the following environment variables to point to the compilers, flags, config files etc. that you want to use during building and running the benchmarks.

* CC - C Compiler binary
* CXX - C++ compiler binary
* FC - Fortran compiler binary
* CFLAGS - additional C compiler flags
* CXXFLAGS - additional C++ compiler flags
* FFLAGS - additional Fortran compiler flags

Following are SPEC benchmark related variables you should set.

* SPEC2006_CONFIG - config file to be used for SPEC2006 benchmarks
* SPEC2017_CONFIG - config file to be used for SPEC2017 benchmarks

Sample invocation of `run_bench.sh` script is as follows.

`./run_bench.sh <action> <suite_type> <bench_suite> <individual_bench> <additional_args>`

where,

* action - build/run
* suite_type - vector/scalar
* bench_suite - for scalar this can be spec2006/spec2017/nas; for vector this can be simd/x265/pfor
* individual_bench - only avaiable for SPEC benchmarks; you can specify an individual benchmark name; if not specified it runs all benchmarks for the given SPEC variant.

Additional positional arguments for benchmark suites

* SPEC2006/SPEC2017 - in positional order (all should be supplied)
  * tune - peak/base
  * size - ref/train/test

Special invocations to run a specific subset of benchmarks

* `./run_bench.sh all` - runs all benchmarks
* `./run_bench.sh vector` - runs all vector benchmarks
* `./run_bench.sh scalar` - runs all scalar benchmarks

# Sample config files

Sample config files for SPEC2006/SPEC2017 are given under the folder scalar/config.

If you opt to use these config files, note that we use internal environment variables
CC1, CXX1, FC1 to transfer the compilers you set by environment variables
CC, CXX, FC to the config script. You are free to modify these config files keeping this fact
in mind. If you use your own config files, the values set by the environment variables CC, CXX
and FC will be ignored and you will need to manually edit the file to point to the compilers
you wish to test.
