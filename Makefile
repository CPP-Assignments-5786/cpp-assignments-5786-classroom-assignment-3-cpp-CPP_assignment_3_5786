CXX=g++
CXXFLAGS=-std=c++17 -Werror -Wsign-conversion
SOURCES=Book.cpp LibraryCard.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

all: demo
	./demo

demo: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestRunner.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test
	./test

TestRunner.o: test.cpp Book.hpp LibraryCard.hpp doctest.h
	$(CXX) $(CXXFLAGS) --compile test.cpp -o TestRunner.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

Book.o: Book.cpp Book.hpp

LibraryCard.o: LibraryCard.cpp LibraryCard.hpp Book.hpp

main.o: main.cpp Book.hpp LibraryCard.hpp

clean:
	rm -f *.o demo test