#include <iostream>
#include <string>
#include <vector>
#include "client.h"
#include "pedidos.h"
#include "vehicle.h"
#include "caminhao.h"


int main()
{
    Client cliente1("Glauber", 38, "Rua 123, 321", "000.111.222-3");
    Client *cliente2 = new Client("Osvaldo", 22, "Rua 123, 321", "333.222.111-0");

    Pedidos pedido1(cliente1, "carro", "Rua 123", "rua 321", 100, "300 litros");

    Caminhao *caminhao2 = new Caminhao(100, 2000, "11111111111111111", "focus", "Rua ###", 3, 3);
    Vehicle veiculo1 = Vehicle(100, 2000, "12312312312312312", "prisma", 3, 3);

    Vehicle::pushVeiculo(100, 2000, "12312312312312312", "prisma", "Rua x");
    Vehicle::buscarVeiculo("12312312312312312");

    if(veiculo1 == Vehicle::vehicleList[0]) printf("Sao iguais\n");
    else printf("Nao sao iguais\n");

    if (caminhao1 == caminhao2)
        printf("Sao iguais\n");
    else
        printf("Nao sao iguais\n");

    std::cout << caminhao1;

    return 0;
}