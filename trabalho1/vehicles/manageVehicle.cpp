#include "vehicle.h"
#include "manageVehicle.h"
#include <iostream>
#include <string>

void manageVehicle::pushVehicle(Vehicle *vehicle)
{
    vehicleList.push_back(vehicle);
}

void manageVehicle::popVehicle(Vehicle *vehicle)
{
    // vehicleList.erase(
    //     std::remove_if(
    //         vehicleList.begin(), 
    //         vehicleList.end(),   
    //         [](Vehicle v){ return v == vehicle; } 
    //     ),
    //     vehicleList.end() 
    // );
}

Vehicle* manageVehicle::searchVehicle(std::string chassi)
{
    for (const auto &vehicle : vehicleList)
    {
        if (vehicle->getChassis() == chassi) return vehicle;
    }
    return nullptr;
}

Vehicle* manageVehicle::search( int loadWeight, std::string address){
    int radius = 10;        // Definindo o raio de busca inicial como 10 km 

    while( radius < 4000){
        for ( auto &vehicle : vehicleList){
            if( vehicle->getAvailable() && vehicle->getLoadCapacity() >= loadWeight && radius>Coordinates::calculate_distance( vehicle->getLocation(), address)){
                return vehicle;
            }
        }
        radius+= 100;       // Aumentando de 100 em 100 o raio de busca até encontrar um veiculo proximo e disponivel
    }
    return nullptr;
}