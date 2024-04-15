#ifndef PEDIDOS_H
#define PEDIDOS_H
#include <string>
#include "vehicle.h"

class GerenciaVehicle
{
private:

    Vehicle vehicle;

public:
    static std::vector<Vehicle> vehicleList;

    void setVehicle(Vehicle vehicle) { this->vehicle = vehicle; }
    Vehicle getVehicle() const { return this->vehicle; }

    static void pushVeiculo(Vehicle vehicle);
    static void popVeiculo();
    static Vehicle buscarVeiculo(std::string chassi);

};

#endif