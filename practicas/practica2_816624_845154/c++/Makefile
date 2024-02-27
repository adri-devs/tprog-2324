PROG := main.exe
SRCS := main.cc instruccion.cc programa.cc
OBJS := $(SRCS:.cc=.o)
CXX := g++
CXXFLAGS := -O2 -std=c++11

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(PROG) $(OBJS)