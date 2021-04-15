all: driver

driver: driver.o miniGit.o
	g++ -std=c++11 -Wall -g driver.o miniGit.o -o main

driver.o: driver.cpp
	g++ -std=c++11 -Wall -g -c driver.cpp

miniGit.o: miniGit.cpp
	g++ -std=c++11 -Wall -g -c miniGit.cpp

clean:
	rm -f driver *.o
