all: test.o string.o
	g++ test.o string.o

test.o: test.cpp
	g++ -std=c++11 -c test.cpp

string.o: string.cpp
	g++ -std=c++11 -c string.cpp

test: all
	./a.out

clean:
	rm *.o ./a.out

valgrind:
	valgrind ./a.out