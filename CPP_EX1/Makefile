# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -g

# Source files
SRCS = Demo.cpp Algorithms.cpp Graph.cpp Test.cpp TestCounter.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HEADERS = Algorithms.hpp Graph.hpp doctest.h

# Targets
all: demo test testcounter

# Main target
demo: Demo.o Algorithms.o Graph.o
	$(CXX) $(CXXFLAGS) -o demo Demo.o Algorithms.o Graph.o

# Test target
test: Test.o Algorithms.o Graph.o
	$(CXX) $(CXXFLAGS) -o test Test.o Algorithms.o Graph.o

# TestCounter target
testcounter: TestCounter.o Algorithms.o Graph.o
	$(CXX) $(CXXFLAGS) -o testcounter TestCounter.o Algorithms.o Graph.o

# Pattern rules for object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target to remove object files and executables
clean:
	rm -f $(OBJS) demo test testcounter