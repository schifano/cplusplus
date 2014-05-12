hash: HashTable.o main.o
	g++ -o hash HashTable.o main.o

HashTable.o: HashTable.cpp HashTable.h Date.h
	g++ -c HashTable.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm hash *.o
