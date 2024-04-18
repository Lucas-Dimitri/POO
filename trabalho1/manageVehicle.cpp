#include "vehicle.h"
#include "manageVehicle.h"
#include <iostream>
#include <string>

void manageVehicle::pushVehicle(Vehicle vehicle)
{
    vehicleList.push_back(vehicle);
}

void manageVehicle::popVehicle()
{
    if (!vehicleList.empty()) vehicleList.pop_back();
}

Vehicle manageVehicle::searchVehicle(std::string chassis)
{
    for (const auto &vehicle : vehicleList)
    {
        if (vehicle.getChassis() == chassis) return vehicle;
    }
}