#ifndef TRANSPORTATION_H
#define VEHICLE_H

#include <string>
#include <vector>
#include "order.h"

class Transportation
{
private:
    Order order;

public:

    int setcapacity(int capacity);
    int getCapacity() const;
};

#endif