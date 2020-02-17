all: test_code.gcno
	gcov ./test_code.gcno 

test_code.gcno: test.out
	valgrind ./test.out

test.out: test_code.o textfilereader.o	
	c++ -o test.out -g -O0 -fprofile-arcs -ftest-coverage test_code.o textfilereader.o

textfilereader.o: textfilereader.cpp
	c++ -c -g -O0 -fprofile-arcs -ftest-coverage textfilereader.cpp

test_code.o: test_code.cpp clean
	c++ -c -g -O0 -fprofile-arcs -ftest-coverage test_code.cpp

clean: 
	rm *.gcno *.gcov *.gcda *.out *.dSYM *.o || true

