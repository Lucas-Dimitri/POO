#include <iostream>
#include <string>
#include <vector>
#include "client.h"
#include "pedidos.h"
#include "vehicle.h"
#include "caminhao.h"

void adicionarVeiculo(std::vector<Vehicle>& veiculos, int capacidade_carga, int ano_fabricacao, std::string chassi, std::string modelo, std::string localizacao)
{
    veiculos.push_back(Vehicle(capacidade_carga, ano_fabricacao, chassi, modelo, localizacao));
}

void removerVeiculo(std::vector<Vehicle> veiculos) { if (!veiculos.empty()) veiculos.pop_back(); }

void buscarVeiculo(std::vector<Vehicle> veiculos, std::string chassi)
{
    for (auto& vehicle : veiculos) if (vehicle.getChassi() == chassi)
    {
        std::cout << "Model: " << vehicle.getModelo() << std::endl;
        std::cout << "Chassis: " << vehicle.getChassi() << std::endl;
        std::cout << "Year: " << vehicle.getAnoFabricacao() << std::endl;
        std::cout << "Capacity: " << vehicle.getCapacidade() << std::endl;
        std::cout << "Location: " << vehicle.getLocalizacao() << std::endl;
    }
}

int main()
{

    Client cliente1("Glauber", 38, "Rua 123, 321", "000.111.222-3");
    Client *cliente2 = new Client("Osvaldo", 22, "Rua 123, 321", "333.222.111-0");

    Pedidos pedido1(cliente1, "carro", "Rua 123", "rua 321", 100, "300 litros");

    Caminhao *caminhao1 = new Caminhao(100, 2000, "11111111111111111", "focus", "Rua ###", 3);

    Vehicle veiculo1 = Vehicle(100, 2000, "12312312312312312", "prisma", "Rua x");

    std::vector<Vehicle> meusVeiculos;
    
    adicionarVeiculo(meusVeiculos, 100, 2000, "12312312312312312", "prisma", "Rua x");

    if (meusVeiculos.empty())
    {
        std::cout << "vazia\n";
    }
    
    buscarVeiculo(meusVeiculos, "12312312312312312");
}