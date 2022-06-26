FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	cp ./lib/libtrastienda.so ./lib/libproducto.so ./bin
	g++ -g -o bin/tiendacliente bin/main.o -L./lib -ltrastienda -lproducto
	
clean:
	rm -Rf bin