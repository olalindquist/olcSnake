full:
	make compile && make run
run:
	./test

compile: main.o Player.o Apple.o Tail.o
	g++ -o test main.o Player.o Apple.o Tail.o -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17
main.o:
	g++ -c main.cc -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17
Player.o:
	g++ -c Player.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17
Apple.o:
	g++ -c Apple.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17
Tail.o:
	g++ -c Tail.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17


memtest:
	valgrind --leak-check=full --show-leak-kinds=all -s ./test



fullCompile:
	g++ -o test main.cc Player.cpp Apple.cpp Tail.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17
