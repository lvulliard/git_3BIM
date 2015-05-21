all: coevolution.out

coevolution.out: main.cpp Environment.o Host.o 
	g++ -o coevolution.out -Wall Environment.o Host.o main.cpp


Environment.o: Environment.cpp Environment.h
	g++ -o Environment.o -c -Wall Environment.cpp

Host.o: Host.cpp Host.h
	g++ -o Host.o -c -Wall Host.cpp


clean:
	rm *.o

#miniAevol: main.o
#	g++ main.o -o miniAevol `pkg-config gtkmm-3.0 --cflags --libs`

#main.o: main.cpp
#	g++ -g -c main.cpp `pkg-config gtkmm-3.0 --cflags --libs`