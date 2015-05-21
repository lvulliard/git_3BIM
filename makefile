miniAevol: main.o
	g++ main.o -o miniAevol `pkg-config gtkmm-3.0 --cflags --libs`

main.o: main.cpp
	g++ -g -c main.cpp `pkg-config gtkmm-3.0 --cflags --libs`