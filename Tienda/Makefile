FLAGS = -g -c --std=c++17

all:
	mkdir -p obj
	mkdir -p bin
	g++ $(FLAGS) src/tienda.cpp -o obj/tienda.o
	g++ $(FLAGS) src/producto.cpp -o obj/producto.o
	g++ -shared -o bin/libtienda.so obj/tienda.o obj/producto.o
	mkdir -p bin/include
	cp src/tienda.h src/producto.h ./bin/include
	

clean:
	rm -Rf bin