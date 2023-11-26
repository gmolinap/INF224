# Program name
PROG = main

# Source files (add more if needed)
SOURCES = main.cpp MultimediaManager.cpp Video.cpp Film.cpp Photo.cpp Group.cpp Multimedia.cpp

# Object files
OBJ = $(SOURCES:.cpp=.o)

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++14 -Wall -g

# Linker flags
LDFLAGS =

# Libraries
LDLIBS =

# Targets
all: $(PROG)

$(PROG): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

# Rules to generate object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Target to run the program
run: $(PROG)
	./$(PROG)

# Clean target
clean:
	rm -f $(PROG) $(OBJ)
