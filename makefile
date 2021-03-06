all: coevolution.out

coevolution.out: main.cpp DefVal.h Environment.o Host.o Main_Window.o
	g++ -o coevolution.out -Wall Main_Window.o Environment.o Host.o main.cpp `pkg-config gtkmm-3.0 --cflags --libs`

Environment.o: Environment.cpp Environment.h DefVal.h
	g++ -o Environment.o -c -Wall Environment.cpp

Main_Window.o: Main_Window.cpp Main_Window.h DefVal.h Environment.o
	g++ -o Main_Window.o -c -Wall Main_Window.cpp `pkg-config gtkmm-3.0 --cflags --libs`

Host.o: Host.cpp Host.h DefVal.h
	g++ -o Host.o -c -Wall Host.cpp

clean:
	rm *.o
