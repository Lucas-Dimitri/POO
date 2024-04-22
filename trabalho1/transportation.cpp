#include <iostream>
#include <ostream>
#include "transportation.h"
#include "vehicle.h"
#include "order.h"
#include "manageVehicle.h"

void prepareOrder(Order order)
{
    int load = 0;
    for(auto &vehicle : manageVehicle::vehicleList)
    {
        load += vehicle.getLoadCapacity();
        vehicle.available = false;
        if (order.getLoadVolume() <= load) return;
    }
}