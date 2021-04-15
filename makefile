all: Driver

Driver: Driver.o MovieTree.o
	g++ -std=c++11 -Wall -g Driver.o MovieTree.o -o main

Driver.o: Driver.cpp
	g++ -std=c++11 -Wall -g -c Driver.cpp

MovieTree.o: MovieTree.cpp
	g++ -std=c++11 -Wall -g -c MovieTree.cpp

clean:
	rm -f main *.o
