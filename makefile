all: driver

driver: driver.o miniGit.o
	g++ -std=c++17 -lstdc++fs -Wall -g driver.o miniGit.o -o main

driver.o: driver.cpp
	g++ -std=c++17 -lstdc++fs -Wall -g -c driver.cpp

miniGit.o: miniGit.cpp
	g++ -std=c++17 -lstdc++fs -Wall -g -c miniGit.cpp

clean:
	rm -f driver *.o
# ad

