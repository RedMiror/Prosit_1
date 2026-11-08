CXX ?= c++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -Wpedantic -O2

SOURCES = main.cpp Point2.cpp Vector2.cpp Segment2.cpp
OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: all clean
all: main

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) main
