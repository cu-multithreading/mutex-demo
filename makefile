all: mutex-demo.prog

mutex-demo.prog: mutex-demo.cpp
	g++ mutex-demo.cpp -o mutex-demo.prog
