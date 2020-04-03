all: test.o uniqueptr.o
	g++ test.o uniqueptr.o

test.o: test.cpp
	g++ -std=c++11 -c test.cpp

uniqueptr.o: uniqueptr.cpp
	g++ -std=c++11 -c uniqueptr.cpp

test: all
	./a.out

clean:
	rm *.o ./a.out
