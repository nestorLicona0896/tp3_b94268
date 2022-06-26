#include <iostream>
#include <string>
#include <fstream>

#include "trastienda.h"
#include "producto.h"

using namespace std;

using namespace tp3;

int main()
{

    /*cout << "Tamaño en bytes de una variable int: " << sizeof(int) << endl;
    cout << "Tamaño en bytes de una variable short: " << sizeof(short) << endl;
    cout << "Tamaño en bytes de una variable long: " << sizeof(long) << endl;
    cout << "Tamaño en bytes de una variable float: " << sizeof(float) << endl;
    cout << "Tamaño en bytes de una variable double: " << sizeof(double) << endl;
    cout << "Tamaño en bytes de una variable empleado: " << sizeof(Producto) << endl; */
    
    // guardar una trastienda en un archivo binario
    //Trastienda *trastienda = new Trastienda();
    Trastienda *trastienda = new Trastienda("micho", "micho.com", "de tu fondillo pa'a dentro", "bizcocho");
    
    Producto *producto1 = new Producto(1, "harina", 1);
    Producto *producto2 = new Producto(2, "leche", 2);
    Producto *producto3 = new Producto(3, "pescado", 3);
    Producto *producto4 = new Producto(4, "huevos", 4);

    trastienda->AgregarProducto(producto1);
    trastienda->AgregarProducto(producto2);
    trastienda->AgregarProducto(producto3);
    trastienda->AgregarProducto(producto4);

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

    return 0;
}