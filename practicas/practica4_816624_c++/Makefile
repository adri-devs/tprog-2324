PROG:=main
SRCS:=main.cc shell.cc nodo.cc fichero.cc directorio.cc enlace.cc

CXX:=g++ -Wall -std=c++11

OBJS:=$(SRCS:.cc=.o)
DEPS:=$(SRCS:.cc=.d)

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) -o $@ $^

.cc.o:
	$(CXX) -c -MMD $<

.PHONY: edit go

go: $(PROG)
	$(PROG)

edit:
	@geany -s -i $(SRCS) *.h &

clean:
	@rm -f $(PROG) $(OBJS) $(DEPS) *.gch core tags

-include $(DEPS)