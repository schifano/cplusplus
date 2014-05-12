CFLAGS= -I/usr/include -I/usr/local/include -I.
LDFLAGS= -L/usr/lib -lGL -lGLU -lm -l:libglut.so.3.8.0

BINARIES=FindFlightPath GraphTest

all: $(BINARIES)

FindFlightPath: FindFlightPath.o Graph.o
	g++ $(LDFLAGS) -o FindFlightPath FindFlightPath.o Graph.o
	
GraphTest: GraphTest.o Graph.o
	g++ -o GraphTest GraphTest.o Graph.o

FindFlightPath.o: FindFlightPath.cpp Graph.h Graph.cpp GPSLocation.h
	g++ -c $(CFLAGS) FindFlightPath.cpp

Graph.o: Graph.cpp Graph.h PriorityQueue.h GPSLocation.h
	g++ -c Graph.cpp

GraphTest.o: GraphTest.cpp GPSLocation.h
	g++ -c GraphTest.cpp

clean:
	rm $(BINARIES) *.o
