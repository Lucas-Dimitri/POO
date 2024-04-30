#include <iostream>
#include <string>
#include "vehicle.h"
#include "truck.h"

Truck::Truck() : Vehicle() {}
Truck::Truck(int loadCapacity, int yearProduction, std::string chassiss, std::string model, int latitude, int longitude, int height, bool available) : Vehicle(loadCapacity, yearProduction, chassiss, model, latitude, longitude, height, available){}
Truck::~Truck(){}

bool operator==(const Truck &lhs, const Truck &rhs)
{
    return lhs.getChassis() == rhs.getChassis() &&
           lhs.getHeight() == rhs.getHeight() &&
           lhs.getLoadCapacity() == rhs.getLoadCapacity() &&
           lhs.getLocation() == rhs.getLocation() &&
           lhs.getModel() == rhs.getModel() &&
           lhs.getYearProduction() == rhs.getYearProduction() &&
           lhs.getHeight() == rhs.getHeight();
}

std::ostream &operator<<(std::ostream &os, const Truck &truck)
{
    os << "Height: " << truck.getHeight() << "\n"
       << "Chassis: " << truck.getChassis() << "\n"
       << "Load Capacity: " << truck.getLoadCapacity() << "\n"
       << "Model: " << truck.getModel() << "\n"
       << "Year of Production: " << truck.getYearProduction() << "\n"
       << "Truck height: " << truck.getHeight() << "\n";
    return os;
}