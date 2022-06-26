#include <gtest/gtest.h>
#include "./../src/producto.h"

namespace tp3
{
    TEST(Producto_Test, Test_Constructor)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto = new Producto();

        // Act - ejecute la operación
        int actual = 2;
        int esperada = 2;

        delete producto;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }


}