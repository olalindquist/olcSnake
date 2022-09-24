full:
	make compile && make run
run:
	./test
fullCompile:
	make clean && make compile

compile: main.o Player.o Apple.o Tail.o TailPiece.o TailList.o TailListNode.o
	g++ -o test main.o Player.o Apple.o Tail.o TailPiece.o TailListNode.o TailList.o -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

main.o: Player.o Apple.o Tail.o TailPiece.o TailList.o TailListNode.o
	g++ -c main.cc -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

Player.o:
	g++ -c Player.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

Apple.o:
	g++ -c Apple.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

TailList.o: TailPiece.o TailListNode.o
	g++ -c TailList.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

TailListNode.o: TailPiece.o
	g++ -c TailListNode.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

TailPiece.o:
	g++ -c TailPiece.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

Tail.o: TailList.o TailPiece.o
	g++ -c Tail.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

memtest:
	valgrind --leak-check=full --show-leak-kinds=all -s ./test

clean:
	rm *.o
