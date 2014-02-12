all: tsort

tsort: main.o topo_order.o
	g++ main.o topo_order.o -o tsort

main.o: main.cpp
	g++ -c main.cpp

topo_order.o: topo_order.cpp
	g++ -c topo_order.cpp

clean:
	rm -rf *.o tsort
