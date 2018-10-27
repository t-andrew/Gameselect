# Makefile for Gameselect
#

TARGET := GameSelect
CXX :=g++
CXXFLAGS :=-Wall -O3 -c
LINKER := g++ -o

SRCDIR := src
SRC := $(wildcard $(SRCDIR)/*.cpp)
OBJ := $(patsubst %.cpp,%.o,$(SRC))

all: $(TARGET)

$(TARGET): $(OBJ)
	$(LINKER) $@ $(SRCDIR)/*.o

%o: %c
	$(CXX) $(CXXFLAGS) $(SRCDIR)/$<

.PHONY: clean
clean:
	rm -f *.o
	rm -f src/*.o
