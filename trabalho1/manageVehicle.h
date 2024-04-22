#ifndef MANAGEVEHICLE_H
#define MANAGEVEHICLE_H
#include <string>
#include <vector>
#include "vehicle.h"
#include "truck.h"

class manageVehicle
{
    public:
        static std::vector<Vehicle> vehicleList;

        static void pushVehicle(Vehicle vehicle);
        static void pushVehicle(Truck truck);
        static void popVehicle();
        static Vehicle searchVehicle(std::string chassi);
};

#endif