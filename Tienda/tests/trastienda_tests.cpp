#include <gtest/gtest.h>
#include "./../src/trastienda.h"
#include "./../src/producto.h"
#include <string>
#include <fstream>
#include <sstream>

namespace tp3
{
    TEST(Tienda_Test, Test_Constructor_Trastienda)
    {
        /// AAA

        // Arrange - configurar el escenario
        Trastienda *tienda = new Trastienda();

        // Act - ejecute la operación
        string actual = tienda->ObtenerNombre();
        string esperada = "";

        delete tienda;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }

    TEST(Tienda_Test, Test_Constructor2_Trastienda)
    {
        /// AAA

        // Arrange - configurar el escenario
        Trastienda *tienda = new Trastienda("Mi Tienda", "", "", "");

        // Act - ejecute la operación
        string actual = tienda->ObtenerNombre();
        string esperada = "Mi Tienda";

        delete tienda;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }

    TEST(Tienda_Test, Test_Editar_Nombre_Tienda)
    {
        /// AAA

        // Arrange - configurar el escenario
        Trastienda *tienda = new Trastienda("", "", "", "");
        tienda->EditarNombre("Mi Tienda1");

        // Act - ejecute la operación
        string actual = tienda->ObtenerNombre();
        string esperada = "Mi Tienda1";

        delete tienda;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }

    TEST(Tienda_Test, Test_Editar_Web_Tienda)
    {
        /// AAA

        // Arrange - configurar el escenario
        Trastienda *tienda = new Trastienda("", "", "", "");
        tienda->EditarSitioWeb("MiWeb1.com");

        // Act - ejecute la operación
        string actual = tienda->ObtenerSitioWeb();
        string esperada = "MiWeb1.com";

        delete tienda;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }

    TEST(Tienda_Test, Test_Editar_Direccion_Tienda)
    {
        /// AAA

        // Arrange - configurar el escenario
        Trastienda *tienda = new Trastienda("", "", "", "");
        tienda->EditarDireccion("100 este 25 norte edificio color naranja");

        // Act - ejecute la operación
        string actual = tienda->ObtenerDireccion();
        string esperada = "100 este 25 norte edificio color naranja";

        delete tienda;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }

    TEST(Tienda_Test, Test_Editar_Telefono_Tienda)
    {
        /// AAA

        // Arrange - configurar el escenario
        Trastienda *tienda = new Trastienda("", "", "", "");
        tienda->EditarTelefono("87654321");

        // Act - ejecute la operación
        string actual = tienda->ObtenerTelefono();
        string esperada = "87654321";

        delete tienda;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }

    
    TEST(Tienda_Test, Test_Obtener_Nombre_Tienda)
    {
        /// AAA

        // Arrange - configurar el escenario
        Trastienda *tienda = new Trastienda("la tienda", "", "", "");
        

        // Act - ejecute la operación
        string actual = tienda->ObtenerNombre();
        string esperada = "la tienda";

        delete tienda;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }

    TEST(Tienda_Test, Test_Obtener_Web_Tienda)
    {
        /// AAA

        // Arrange - configurar el escenario
        Trastienda *tienda = new Trastienda("", "latienda.com", "", "");
        

        // Act - ejecute la operación
        string actual = tienda->ObtenerSitioWeb();
        string esperada = "latienda.com";

        delete tienda;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }

    TEST(Tienda_Test, Test_Obtener_Direccion_Tienda)
    {
        /// AAA

        // Arrange - configurar el escenario
        Trastienda *tienda = new Trastienda("", "", "100 este 25 norte", "");
        

        // Act - ejecute la operación
        string actual = tienda->ObtenerDireccion();
        string esperada = "100 este 25 norte";

        delete tienda;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }

    TEST(Tienda_Test, Test_Obtener_Telefono_Tienda)
    {
        /// AAA

        // Arrange - configurar el escenario
        Trastienda *tienda = new Trastienda("", "", "", "11112222");
        

        // Act - ejecute la operación
        string actual = tienda->ObtenerTelefono();
        string esperada = "11112222";

        delete tienda;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }

    TEST(Tienda_Test, Test_Agregar_Producto_Tienda)
    {
        /// AAA

        // Arrange - configurar el escenario
        Trastienda *tienda = new Trastienda();
        Producto *producto = new Producto(1, "producto1", 1);

        tienda->AgregarProducto(producto);

        // Act - ejecute la operación
        int actual = tienda->ObtenerProducto(1)->ObtenerId();
        int esperado = producto->ObtenerId();

        delete tienda;

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }

    TEST(Tienda_Test, Test_Editar_Producto_Tienda)
    {
        /// AAA

        // Arrange - configurar el escenario
        Trastienda *tienda = new Trastienda();
        Producto *producto = new Producto(1, "producto1", 1);
        tienda->AgregarProducto(producto);
        tienda->EditarProducto(1, 1, "producto1", 3);

        // Act - ejecute la operación
        int actual = tienda->ObtenerProducto(1)->ObtenerExistencias();
        int esperado = 3;

        delete tienda;

        // Assert - valide los resultados
        EXPECT_EQ(esperado , actual);
    }

    /*TEST(Tienda_Test, Test_Eliminar_Producto_Tienda)
    {
        /// AAA

        // Arrange - configurar el escenario
        Trastienda *tienda = new Trastienda();
        Producto *producto = new Producto(1, "producto1", 1);
        tienda->AgregarProducto(producto);        

        // Act - ejecute la operación
        bool actual = tienda->EliminarProducto(1);       

        delete tienda;

        // Assert - valide los resultados
        EXPECT_TRUE(actual);
    }*/

    TEST(Tienda_Test, Test_Obtener_Producto_Tienda)
    {
        /// AAA

        // Arrange - configurar el escenario
        Trastienda *tienda = new Trastienda();
        Producto *producto = new Producto(1, "producto1", 1);
        tienda->AgregarProducto(producto);
        

        // Act - ejecute la operación
        int actual = tienda->ObtenerProducto(producto->ObtenerId())->ObtenerId();
        int esperado = 1;
    

        delete tienda;

        // Assert - valide los resultados
        EXPECT_EQ(actual, esperado);
    }

    TEST(Tienda_Test, Test_Obtener_Inventario_Tienda)
    {
        /// AAA

        // Arrange - configurar el escenario
        Trastienda *tienda = new Trastienda();
        Producto *producto = new Producto(1, "producto1", 1);
        tienda->AgregarProducto(producto);
        

        // Act - ejecute la operación
        int actual = tienda->ObtenerInventario().at(producto->ObtenerId()-1)->ObtenerId();
        int esperado = 1;
    

        delete tienda;

        // Assert - valide los resultados
        EXPECT_EQ(actual, esperado);
    }

    TEST(Planilla_Test, Escribir_Leer_Archivo_Binario_Test)
    {
        /// AAA

        // Arrange - configurar el escenario
        Trastienda *trastiendaEsperada = new Trastienda("tienda", ".com", "150 este", "12345678");

        Producto *producto1 = new Producto(1, "masa", 1);
        trastiendaEsperada->AgregarProducto(producto1);

        // Act - ejecute la operación
        // Escribir un archivo de prueba
        ofstream archivoSalida;
        archivoSalida.open("archivo_test.dat", ios::out|ios::binary);

        if (!archivoSalida.is_open())
        {
            cerr << "No se pudo abrir archivo archivo_test.dat para escribir los datos";
            FAIL();
        }

        trastiendaEsperada->GuardarEnStreamBinario(&archivoSalida);

        archivoSalida.close();

        // Leer el archivo de prueba
        ifstream archivoEntrada;
        archivoEntrada.open("archivo_test.dat", ios::in|ios::binary);

        if (!archivoEntrada.is_open())
        {
            cerr << "No se pudo abrir archivo archivo_test.dat para leer los datos";
            FAIL();
        }
    
        Trastienda *trastiendaLeida = new Trastienda();
        trastiendaLeida->CargarDesdeStreamBinario(&archivoEntrada);

        string salidaTiendaLeida = trastiendaLeida->MostrarProductos();

        delete trastiendaLeida;
        delete trastiendaEsperada;

        string esperado = "tienda\nweb: .com\ndireccion: 150 este\ntelefono: 12345678\ninventario:\n1 - masa, 1\n"; 
        //string esperad0 = trastiendaEsperada->MostrarProductos();

        // Primero, validar la salida de la planilla esperada sea correcta
        EXPECT_EQ(salidaTiendaLeida, esperado);
    }


    TEST(Planilla_Test, Test_Mostrar_Tienda)
    {
        /// AAA

        // Arrange - configurar el escenario
        Trastienda *trastiendaEsperada = new Trastienda("tienda", ".com", "150 este", "12345678");

        Producto *producto1 = new Producto(1, "masa", 1);
        trastiendaEsperada->AgregarProducto(producto1);

        // Act - ejecute la operación
        string actual = trastiendaEsperada->MostrarProductos();
        string esperada = "tienda\nweb: .com\ndireccion: 150 este\ntelefono: 12345678\ninventario:\n1 - masa, 1\n";
        
        EXPECT_EQ(esperada, actual);
    }
    


}