# This is an example make file

CXX = g++
CXXFLAGS = -std=c++17 -Wall

# runs for "make all"
all: main

# runs for "make target1"
# the line below this one must be TABBED in (not spaces!)
# files DependsOn.o and main.cpp will be monitored for changes to know if it needs to be re-made
main: pe3_references.cpp
	$(CXX) $(CXXFLAGS) pe3_references.cpp -o main

# pe3_references.o: pe3_references.cpp
# 	$(CXX) $(CXXFLAGS) -c pe3_references.cpp

# runs for "make clean"
clean:
	rm main