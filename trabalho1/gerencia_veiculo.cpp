#include "vehicle.h"
#include "gerencia_veiculo.h"
#include <iostream>
#include <string>

void GerenciaVehicle::pushVeiculo(Vehicle vehicle)
{
    vehicleList.push_back(vehicle);
}

void GerenciaVehicle::popVeiculo()
{
    if (!vehicleList.empty())
        vehicleList.pop_back();
}

Vehicle GerenciaVehicle::buscarVeiculo(std::string chassi)
{
    for (const auto &vehicle : vehicleList)
    {
        if (vehicle.getChassi() == chassi) return vehicle;
    }
}