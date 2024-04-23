#include <iostream>
#include <ostream>
#include "transportation.h"
#include "vehicle.h"
#include "order.h"
#include "manageVehicle.h"



std::vector<Vehicle> prepareOrder(Order order, std::vector<Vehicle> vehicleForOrder)
{
    int load = 0;
    for(auto &vehicle : manageVehicle::vehicleList)
    {
        if(vehicle.getAvailable())
        {
            load += vehicle.getLoadCapacity();
            vehicle.setAvailable(false);
            vehicleForOrder.push_back(vehicle);

            if (order.getLoadVolume() <= load)
                return vehicleForOrder;
        }
    }
}