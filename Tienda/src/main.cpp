#include <iostream>
#include <string>
#include <fstream>

#include "trastienda.h"
#include "producto.h"

using namespace std;

using namespace tp3;

int main()
{

    /* cout << "Tamaño en bytes de una variable empleado: " << sizeof(Trastienda) << endl;*/ 
    
    // guardar una trastienda en un archivo binario
    Trastienda *trastienda = new Trastienda("TIENDA", "algo.com", "100 e, 25 n, C-1", "87654321");

    Producto *producto1 = new Producto(1, "harina", 2);
    Producto *producto2 = new Producto(2, "leche", 2);
    Producto *producto3 = new Producto(3, "pescado", 3);
    Producto *producto4 = new Producto(4, "huevos", 4);
    Producto *producto5 = new Producto(5, "arroz", 8);
    Producto *producto6 = new Producto(6, "desinfectante", 5);
    Producto *producto7 = new Producto(7, "cloro", 6);
    Producto *producto8 = new Producto(8, "detergente", 1);

    trastienda->AgregarProducto(producto1);
    trastienda->AgregarProducto(producto2);
    trastienda->AgregarProducto(producto3);
    trastienda->AgregarProducto(producto4);
    trastienda->AgregarProducto(producto5);
    trastienda->AgregarProducto(producto6);
    trastienda->AgregarProducto(producto7);
    trastienda->AgregarProducto(producto8);

    ofstream archivoSalida;
    archivoSalida.open("trastienda.dat", ios::out | ios::binary);
    if (!archivoSalida.is_open())
    {
        cerr << "No se pudo abrir archivo trastienda.dat para escribir los datos";
        return -1;
    }
    trastienda->GuardarEnStreamBinario(&archivoSalida);
    archivoSalida.close();

    delete trastienda;

    // Ejemplo de leer trastienda desde un archivo binario
    
    ifstream archivoEntrada;
    archivoEntrada.open("trastienda.dat", ios::in|ios::binary);

    if (!archivoEntrada.is_open())
    {
        cerr << "No se pudo abrir archivo trastienda.dat para leer los datos";
        return -1;
    }
    
    Trastienda *trastienda1 = new Trastienda();

    trastienda1->CargarDesdeStreamBinario(&archivoEntrada);

    trastienda1->MostrarProductos();

    delete trastienda1;

    archivoEntrada.close();

    return 0;
}