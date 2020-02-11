# This is an example make file

CXX = g++
CXXFLAGS = -std=c++17 -Wall

# runs for "make all"
all: main

# runs for "make target1"
# the line below this one must be TABBED in (not spaces!)
# files DependsOn.o and main.cpp will be monitored for changes to know if it needs to be re-made
main: Point.o main.cpp
	$(CXX) $(CXXFLAGS) main.cpp Point.o -o main

Point.o: Point.cpp
	$(CXX) $(CXXFLAGS) -c Point.cpp

# runs for "make clean"
clean:
	rm Point.o main 