all: coevolution.out

coevolution.out: main.cpp Environment.o Host.o 
	g++ -o coevolution.out -Wall Environment.o Host.o main.cpp `pkg-config gtkmm-3.0 --cflags --libs`


Environment.o: Environment.cpp Environment.h
	g++ -o Environment.o -c -Wall Environment.cpp

Host.o: Host.cpp Host.h
	g++ -o Host.o -c -Wall Host.cpp


clean:
	rm *.o