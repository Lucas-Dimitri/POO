#include <iostream>
#include <string>
#include <vector>
#include "client.h"
#include "pedidos.h"
#include "vehicle.h"
#include "caminhao.h"


int main()
{
    Vehicle veiculo1 = Vehicle(100, 2000, "12312312312312312", "prisma", "Rua x");

    Vehicle::pushVeiculo(100, 2000, "12312312312312312", "prisma", "Rua x");
    Vehicle::buscarVeiculo("12312312312312312");

    return 0;
}