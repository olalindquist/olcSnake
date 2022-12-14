full:
	make compile && make run
run:
	./test
compile:
	g++ -o test main.cc -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17
memtest:
	valgrind --leak-check=full --show-leak-kinds=all -s ./test
