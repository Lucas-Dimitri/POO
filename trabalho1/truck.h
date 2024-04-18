#ifndef TRUCK_H
#define TRUCK_H

#include "vehicle.h"
#include <string>

class Truck : public Vehicle
{
    public:
        Truck(int loadCapacity, int yearProduction, std::string chassis, std::string model,int latitude, int longitude, int height);
        Truck();
        ~Truck();

        int setHeight(int height);
        int getHeight() const;

        friend std::ostream &operator<<(std::ostream &os, const Truck &truck);
        friend bool operator==(const Truck &lhs, const Truck &rhs);

    private:
        int height;
};

#endif