#include <iostream>
#include <string>
#include "client.h"
#include "pedidos.h"
#include "vehicle.h"


int main()
{
    Vehicle carro1;
    carro1.setAnoFabricacao(2019);
    carro1.setCapacidade(1542);
    carro1.setChassi("9BD111060T5002156");
    carro1.setLocalizacao("Florida, EUA");
    carro1.setModelo("Toyota Supra");
    carro1.setTipo("CarrO");
    

    std::cout << carro1.getModelo() << "\n" << carro1.getTipo() << "\n";

    Client cliente1("Glauber", 38, "Rua 123, 321", "000.111.222-3");

    std::cout << cliente1.getCPF() << "\n";

    Pedidos pedido1(cliente1, "carro", "Rua 123", "rua 321", 100, "300 litros");

    Client *cliente2 = new Client("Osvaldo", 22, "Rua 123, 321", "333.222.111-0");

    std::cout << cliente2->getNome() << "\n";

    std::cout << pedido1.getLocalColeta() << "\n";

    pedido1.setLocalColeta("Rua 123123");

    std::cout << pedido1.getLocalColeta() << "\n";

}