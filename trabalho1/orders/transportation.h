#ifndef TRANSPORTATION_H
#define TRANSPORTATION_H

#include <string>
#include <vector>
#include "vehicle.h"
#include "order.h"

class Transportation
{
    public:
        std::vector<Vehicle> prepareOrder(Order order, std::vector<Vehicle> vehicleForOrder);
        Order order;
        std::vector<Vehicle> vehicleForOrder;
    
};

#endif