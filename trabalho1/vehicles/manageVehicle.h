#ifndef MANAGEVEHICLE_H
#define MANAGEVEHICLE_H
#include <string>
#include <vector>
#include "vehicle.h"
#include "truck.h"

class manageVehicle
{
    public:
        std::vector<Vehicle*> vehicleList; // Transformei em uma variavel de instancia e privada 
    public:

        void pushVehicle(Vehicle *vehicle);
        void popVehicle( Vehicle *vehicle);
        Vehicle* searchVehicle(std::string chassi);
        Vehicle* searchBy( int loadWeight);
        Vehicle* search( int loadWeight, std::string address);
};

#endif