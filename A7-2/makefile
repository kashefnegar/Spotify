all:a.out

a.out:main.o gerdabServer.o web++.o request.o gerdabify.o spotify.o person.o music.o state.o play_managment.o
	g++ main.o gerdabServer.o web++.o request.o gerdabify.o spotify.o person.o music.o state.o play_managment.o

main.o:main.cpp web++.o gerdabServer.o request.o gerdabify.o
		g++ -c main.cpp

gerdabServer.o: gerdabServer.cpp
		g++ -c gerdabServer.cpp

web++.o: web++.cpp
		g++ -c web++.cpp

request.o:request.cpp request.h gerdabServer.hpp exception.h 
	g++ -c request.cpp

gerdabify.o:gerdabify.cpp gerdabify.h spotify.h
	g++ -c gerdabify.cpp

spotify.o:spotify.cpp spotify.h state.h music.h person.h exception.h
	g++ -c spotify.cpp

person.o:person.cpp person.h music.h exception.h
	g++ -c person.cpp

music.o:music.cpp music.h person.h exception.h
	g++ -c music.cpp

state.o:state.cpp state.h music.h person.h  exception.h play_managment.h
	g++ -c state.cpp

play_managment.o:play_managment.cpp play_managment.h music.h
	g++ -c play_managment.cpp
	
clean:
	rm *.o *.out
