#ifndef MANAGEVEHICLE_H
#define MANAGEVEHICLE_H
#include <string>
#include "vehicle.h"

class manageVehicle
{
    public:
        static std::vector<Vehicle> vehicleList;

        static void pushVehicle(Vehicle vehicle);
        static void popVehicle();
        static Vehicle searchVehicle(std::string chassi);

};

#endif