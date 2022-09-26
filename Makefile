full:
	make compile && make run
run:
	./test
fullCompile:
	make clean && make compile

compile: main.o Player.o Apple.o Tail.o TailPiece.o TailList.o TailListNode.o
	g++ -o test main.o Player.o Apple.o Tail.o TailPiece.o TailListNode.o TailList.o -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

main.o: main.cc Player.cpp Apple.cpp Tail.cpp TailPiece.cpp TailList.cpp TailListNode.cpp
	g++ -c main.cc -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

Player.o: Player.cpp
	g++ -c Player.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

Apple.o: Apple.cpp
	g++ -c Apple.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

Tail.o: Tail.cpp TailList.o TailListNode.o TailPiece.o
	g++ -c Tail.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

TailList.o: TailListNode.o TailList.cpp
	g++ -c TailList.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

TailListNode.o: TailPiece.o TailListNode.cpp
	g++ -c TailListNode.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

TailPiece.o: TailPiece.cpp
	g++ -c TailPiece.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

memtest:
	valgrind --leak-check=full --show-leak-kinds=all -s ./test

clean:
	rm *.o
