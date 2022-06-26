#include "trastienda.h" 
#include <string.h>

using namespace tp3;

Trastienda::Trastienda() {
    strcpy(this->nombre, "");
    strcpy(this->sitioWeb, "");
    strcpy(this->direccion, "");
    strcpy(this->telefono, "");
}

Trastienda::Trastienda(string nombre, string sitio, string direccion, string telefono) {
    strcpy(this->nombre, nombre.c_str());
    strcpy(this->sitioWeb, sitio.c_str());
    strcpy(this->direccion, direccion.c_str());
    strcpy(this->telefono, telefono.c_str());
}

Trastienda::~Trastienda() {
    for(Producto*prod: this->inventario) {
        delete prod;
    }
}

void Trastienda::EditarNombre(string nuevoNombre){
    strcpy(this->nombre, nuevoNombre.c_str());
}

void Trastienda::EditarSitioWeb(string nuevoSitio){
    strcpy(this->sitioWeb, nuevoSitio.c_str());
}

void Trastienda::EditarDireccion(string nuevaDireccion){
    strcpy(this->direccion, nuevaDireccion.c_str());
}

void Trastienda::EditarTelefono(string nuevoTelefono){
    strcpy(this->telefono, nuevoTelefono.c_str());
}

string Trastienda::ObtenerNombre(){
    return this->nombre;
}

string Trastienda::ObtenerSitioWeb(){
    return this->sitioWeb;
}

string Trastienda::ObtenerDireccion(){
    return this->direccion;
}

string Trastienda::ObtenerTelefono(){
    return this->telefono;
}

void Trastienda::AgregarProducto(Producto *unProducto){
    this->inventario.push_back(unProducto);
}

void Trastienda::EditarProducto(int idActual, int nuevoId, string nuevoNombre, int lasExistencias){
    for(Producto *p : this->inventario){
        if(idActual == p->ObtenerId()) {
            p->EditarId(nuevoId);
            p->EditarNombre(nuevoNombre);
            p->EditarExistencias(lasExistencias);
            return;
        }
    }
}

void Trastienda::EliminarProducto(int id){
    for(Producto *p : this->inventario){
        if(id == p->ObtenerId()) {
            delete p;
            return;
        }
    }
}

Producto* Trastienda::ObtenerProducto(int id){
    return this->inventario.at(id);
}

vector<Producto*> Trastienda::ObtenerInventario(){
    return this->inventario;
}


void Trastienda::GuardarEnStreamBinario(ostream *streamSalida)
{
    streamSalida->write((char *)this, sizeof(this->ObtenerNombre()));
    for (Producto *producto : this->ObtenerInventario())
    {
        streamSalida->write((char *)producto, sizeof(Producto));
    }
}

/*ostream& operator << (ostream &o, Trastienda *tienda){

    o << tienda->ObtenerNombre() << endl;
    o << tienda->ObtenerSitioWeb() << endl;
    o << tienda->ObtenerDireccion() << endl;
    o << tienda->ObtenerTelefono() << endl;

    for (Producto *prod : tienda->ObtenerInventario())
    {
        o << prod << endl;
    }
    
    return o;
}*/


