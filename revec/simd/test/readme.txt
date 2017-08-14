rename.sh - creates a test file for each src file -> we are testing all src files seperately.
run.sh - sample shell script to build one test
canonical.in - test harness

Old/ - have all the Test files originally included with the simd repo. These test multiple source files. We are segregating tests so that we test each source file seperately.
Test/ - all the test header files (common content) extracted from the original test cpp files

Just run disttests.py and it will generate the test files. Test/ should already be formed, as this extraction is manual + Old/ should have the original test files.

copytofiles.sh and out.txt can be ignored.
