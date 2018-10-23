TARGET := GameSelect
CXX :=g++
CXXFLAGS :=-Wall -O3 -c
LINKER := g++ -o

SRCDIR := src
SRC := $(wildcard $(SRCDIR)/*.cpp)
OBJ := $(patsubst %.cpp,%.o,$(SRC))
OBJS := $(wildcard *.o)

$(TARGET): $(OBJ)
	$(LINKER) $@ $(OBJS)

$(OBJ): $(SRC)
	@echo "Compiling "@^" ..."
	$(CXX) $(CXXFLAGS) $^

.PHONY: clean
clean:
	rm -f *.o
	rm -f src/*.o
