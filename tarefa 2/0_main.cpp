#include <iostream>
#include <string>
#include "client.h"
#include "pedidos.h"
#include "vehicle.h"
#include "caminhao.h"

int main()
{

    Client cliente1("Glauber", 38, "Rua 123, 321", "000.111.222-3");

    std::cout << cliente1.getCPF() << "\n";

    Pedidos pedido1(cliente1, "carro", "Rua 123", "rua 321", 100, "300 litros");

    Client *cliente2 = new Client("Osvaldo", 22, "Rua 123, 321", "333.222.111-0");

    std::cout << cliente2->getNome() << "\n";

    std::cout << pedido1.getLocalColeta() << "\n";

    pedido1.setLocalColeta("Rua 123123");

    std::cout << pedido1.getLocalColeta() << "\n";

    Caminhao *caminhao1 = new Caminhao(100, 2000, "11111111111111111", "focus", "Rua ###", 3);

    std::cout << caminhao1->getAltura() << "\n";

    std::cout << caminhao1->getChassi() << "\n";

}