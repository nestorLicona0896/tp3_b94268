#include "trastienda.h" 
#include <string.h>

using namespace tp3;

Trastienda::Trastienda() 
{
    strcpy(this->nombre, "");
    strcpy(this->sitioWeb, "");
    strcpy(this->direccion, "");
    strcpy(this->telefono, "");
}

Trastienda::Trastienda(string nombre, string sitio, string direccion, string telefono) 
{
    strcpy(this->nombre, nombre.c_str());
    strcpy(this->sitioWeb, sitio.c_str());
    strcpy(this->direccion, direccion.c_str());
    strcpy(this->telefono, telefono.c_str());
}

Trastienda::~Trastienda() 
{
    for(Producto*prod: this->inventario) {
        delete prod;
    }
}

void Trastienda::EditarNombre(string nuevoNombre)
{
    strcpy(this->nombre, nuevoNombre.c_str());
}

void Trastienda::EditarSitioWeb(string nuevoSitio)
{
    strcpy(this->sitioWeb, nuevoSitio.c_str());
}

void Trastienda::EditarDireccion(string nuevaDireccion)
{
    strcpy(this->direccion, nuevaDireccion.c_str());
}

void Trastienda::EditarTelefono(string nuevoTelefono)
{
    strcpy(this->telefono, nuevoTelefono.c_str());
}

string Trastienda::ObtenerNombre()
{
    return this->nombre;
}

string Trastienda::ObtenerSitioWeb()
{
    return this->sitioWeb;
}

string Trastienda::ObtenerDireccion()
{
    return this->direccion;
}

string Trastienda::ObtenerTelefono()
{
    return this->telefono;
}

void Trastienda::AgregarProducto(Producto *unProducto)
{
    this->inventario.push_back(unProducto);
}

void Trastienda::EditarProducto(int idActual, int nuevoId, string nuevoNombre, int lasExistencias)
{
    for(Producto *p : this->inventario){
        if(idActual == p->ObtenerId()) {
            p->EditarId(nuevoId);
            p->EditarNombre(nuevoNombre);
            p->EditarExistencias(lasExistencias);
            return;
        }
    }
}

void Trastienda::EliminarProducto(int id)
{
    for(Producto *p : this->inventario){
        if(id == p->ObtenerId()) {
            delete p;
            return;
        }
    }
}

Producto* Trastienda::ObtenerProducto(int id)
{
    return this->inventario.at(id);
}

vector<Producto*> Trastienda::ObtenerInventario(){
    return this->inventario;
}

void Trastienda::GuardarEnStreamBinario(ostream *streamSalida)
{          
    streamSalida->write((char *)this->nombre, sizeof(this->nombre));
    streamSalida->write((char *)this->sitioWeb, sizeof(this->sitioWeb));
    streamSalida->write((char *)this->direccion, sizeof(this->direccion));
    streamSalida->write((char *)this->telefono, sizeof(this->telefono));
    for (Producto *producto : this->ObtenerInventario())
    {
        streamSalida->write((char *)producto, sizeof(Producto));
    }
}

void Trastienda::CargarDesdeStreamBinario(istream *streamEntrada)
{
    int BytesTrastienda = sizeof(this->nombre) + sizeof(this->sitioWeb) + sizeof(this->direccion) + sizeof(this->telefono); 
    // Calcule cantidad de registros
    streamEntrada->seekg(0, ios::end);    
    int cantidadBytesEnArchivo = streamEntrada->tellg();
    int cantidadProductos = (cantidadBytesEnArchivo - BytesTrastienda) / sizeof(Producto);
        
    // la info de la tienda: 
    streamEntrada->seekg(0, ios::beg);
    streamEntrada->read((char *)this->nombre, sizeof(this->nombre));
    streamEntrada->read((char *)this->sitioWeb, sizeof(this->sitioWeb));
    streamEntrada->read((char *)this->direccion, sizeof(this->direccion));
    streamEntrada->read((char *)this->telefono, sizeof(this->telefono));

    // Leer cada producto
    streamEntrada->seekg(BytesTrastienda, ios::beg);
    for (int indice = 0; indice < cantidadProductos; indice++)
    {
        Producto *producto = new Producto();
        streamEntrada->read((char *)producto, sizeof(Producto)); // variable para guardar y cuántos bytes leo
        this->AgregarProducto(producto);
    }  
}

void Trastienda::MostrarProductos()
{
    cout << this->ObtenerNombre() << "\nweb: " << this->ObtenerSitioWeb() << "\ndireccion: " << this->ObtenerDireccion() << "\ntelefono: " << this->ObtenerTelefono() << endl;
    cout << "inventario: " << endl;
    for(Producto *p : this->ObtenerInventario()) {
       p->Mostrar();
    }
}

/*ostream& operator << (ostream o, Trastienda *tienda)
{
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


