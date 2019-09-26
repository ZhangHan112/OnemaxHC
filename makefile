all: HC

HC: HC.o main.o 
	g++ -ggdb -O3 -o HC HC.o main.o

HC.o: HC.cpp
	g++ -ggdb -O3 -c HC.cpp

main.o: main.cpp
	g++ -ggdb -O3 -c main.cpp

plot: 
	gnuplot pic.gp

dep:
	echo "Do nothing"

clean:
	rm -f HC HC *.o

cleanDat:
	rm -f *.dat
