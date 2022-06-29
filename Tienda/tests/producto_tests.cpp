#include <gtest/gtest.h>
#include "./../src/producto.h"

namespace tp3
{
    TEST(Producto_Test, Test_Constructor_Producto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto = new Producto();

        // Act - ejecute la operación
        int actual = producto->ObtenerId();
        int esperado = 0;

        delete producto;

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }

    TEST(Producto_Test, Test_Constructor2_Producto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto = new Producto(1, "producto1", 1);

        // Act - ejecute la operación
        int actual = producto->ObtenerId();
        int esperado = 1;

        delete producto;

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }

    TEST(Producto_Test, Test_Editar_Id_Producto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto = new Producto(1, "producto1", 1);
        producto->EditarId(8);

        // Act - ejecute la operación
        int actual = producto->ObtenerId();
        int esperado = 8;

        delete producto;

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }

    TEST(Producto_Test, Test_Editar_Nombre_Producto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto = new Producto(1, "producto1", 1);
        producto->EditarNombre("azucar");

        // Act - ejecute la operación
        string actual = producto->ObtenerNombre();
        string esperado = "azucar";

        delete producto;

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }

    TEST(Producto_Test, Test_Editar_Existencias_Producto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto = new Producto(1, "producto1", 1);
        producto->EditarExistencias(0);

        // Act - ejecute la operación
        int actual = producto->ObtenerExistencias();
        int esperado = 0;

        delete producto;

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }

    TEST(Producto_Test, Test_Obtener_Id_Producto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto = new Producto(1, "producto1", 1);

        // Act - ejecute la operación
        int actual = producto->ObtenerId();
        int esperado = 1;

        delete producto;

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }

    TEST(Producto_Test, Test_Obtener_Nombre_Producto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto = new Producto(1, "producto1", 1);

        // Act - ejecute la operación
        string actual = producto->ObtenerNombre();
        string esperado = "producto1";

        delete producto;

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }

    TEST(Producto_Test, Test_Obtener_Existencias_Producto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto = new Producto(1, "producto1", 1);

        // Act - ejecute la operación
        int actual = producto->ObtenerExistencias();
        int esperado = 1;

        delete producto;

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }

    TEST(Producto_Test, Test_Mostrar_Producto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto = new Producto(1, "producto1", 1);

        // Act - ejecute la operación
        string actual = producto->Mostrar();
        string esperado =  "1 - producto1, 1";

        delete producto;

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);

    }

}