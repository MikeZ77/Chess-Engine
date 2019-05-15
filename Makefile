a.out: main.o board.o engine.o move_gen.o
	g++ main.o board.o engine.o move_gen.o -o a.out

main.o: main.cpp
	g++ -c main.cpp

board.o: board.cpp
	g++ -c board.cpp

engine.o: engine.cpp
	g++ -c engine.cpp

move_gen.o: move_gen.cpp
	g++ -c move_gen.cpp

clean:
	rm *.o a.out