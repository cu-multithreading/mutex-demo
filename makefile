.PHONY: run
.PHONY: clean
g_flags=-pthread

all: demo.prog

demo.prog: source.cpp
	g++ $(g_flags) source.cpp -o demo.prog

debug:
	g++ $(g_flags) -g source.cpp -o demo.prog

run: demo.prog
	./demo.prog
	./demo.prog noMutex

clean:
	rm *.prog *.o -f
