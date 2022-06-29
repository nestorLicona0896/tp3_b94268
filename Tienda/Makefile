FLAGS = -g -c --std=c++17

all:
	
	mkdir -p bin	
	mkdir -p obj	
	g++ $(FLAGS) src/producto.cpp -o obj/producto.o
	g++ $(FLAGS) src/trastienda.cpp -o obj/trastienda.o	
	g++ -shared -o bin/libtrastienda.so obj/trastienda.o
	g++ -shared -o bin/libproducto.so obj/producto.o
	mkdir -p bin/include
	cp src/trastienda.h src/producto.h ./bin/include
	
	
test:
	mkdir -p obj
	mkdir -p bin
	g++ $(FLAGS) src/trastienda.cpp -o obj/trastienda.o
	g++ $(FLAGS) src/producto.cpp -o obj/producto.o
	g++ $(FLAGS) tests/trastienda_tests.cpp -o obj/trastienda_tests.o
	g++ $(FLAGS) tests/producto_tests.cpp -o obj/producto_tests.o
	g++ -g -o bin/tests obj/trastienda.o obj/trastienda_tests.o obj/producto.o obj/producto_tests.o -lgtest -lgtest_main -lpthread 

clean:
	rm -Rf bin