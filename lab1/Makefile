all: approx-pi

approx.o: approx.h approx.cpp
	g++ -c approx.cpp

main.o: main.cpp
	g++ -c main.cpp

approx-pi: approx.o main.o
	g++ -o approx-pi approx.o main.o

test: lab1-test.in
	./approx-pi < lab1-test.in > lab1-mine.out
clean:
	rm -rf approx-pi *.o