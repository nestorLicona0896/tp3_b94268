#include "producto.h"
#include <string.h>

using namespace std;
using namespace tp3;

Producto::Producto(){
    this->id = 0;
    strcpy(this->nombre, "");
    this->existencias = 0;
}

Producto::Producto(int nuevoId, string nombre, int cantidad){
    this->id = nuevoId;
    strcpy(this->nombre, nombre.c_str());
    this->existencias = cantidad;
}

Producto::~Producto(){
    
}

void Producto::EditarId(int nuevoId){
    this->id = nuevoId;
}

void Producto::EditarNombre(string nuevoNombre){
    strcpy(this->nombre, nuevoNombre.c_str());
}

void Producto::EditarExistencias(int nuevaCantidad){
    this->existencias = nuevaCantidad;
}

int Producto::ObtenerId(){
    return this->id;
}

string Producto::ObtenerNombre(){
    return this->nombre;
}

int Producto::ObtenerExistencias(){
    return this->existencias;
}

/*ostream &operator << (ostream &o, Producto *producto){
    o << "[" << producto->ObtenerId() << "] - " << producto->ObtenerNombre() << " " << producto->ObtenerExistencias();  
    return o;
} */