#include <gtest/gtest.h>
#include "./../src/tienda.h"

namespace tp3
{
    TEST(Tienda_Test, Test_Constructor)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tienda = new Tienda();

        // Act - ejecute la operación
        int actual = 2;
        int esperada = 2;

        delete tienda;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);
    }


}