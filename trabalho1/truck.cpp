#include <iostream>
#include <string>
#include "vehicle.h"
#include "truck.h"

Truck::Truck() : Vehicle(), height(0) {}
Truck::Truck(int loadLoadCapacity, int yearProduction, std::string chassiss, std::string model, int latitude, int longitude, int height) : Vehicle(loadLoadCapacity, yearProduction, chassiss, model, latitude, longitude), height(height) {}
Truck::~Truck(){}

int Truck::setHeight(int height)
{
    if (height < 10)
    {
        this->height = height;
        return 1;
    }
    return 0;   
}

int Truck::getHeight() const { return this->height; }

bool operator==(const Truck &lhs, const Truck &rhs)
{
    return lhs.getChassis() == rhs.getChassis() &&
           lhs.getHeight() == rhs.getHeight() &&
           lhs.getLoadCapacity() == rhs.getLoadCapacity() &&
           lhs.getLocation() == rhs.getLocation() &&
           lhs.getModel() == rhs.getModel() &&
           lhs.getYearProduction() == rhs.getYearProduction();
}

std::ostream &operator<<(std::ostream &os, const Truck &caminhao)
{
    os << "Height: " << caminhao.getHeight() << "\n"
       << "Chassis: " << caminhao.getChassis() << "\n"
       << "Load Capacity: " << caminhao.getLoadCapacity() << "\n"
       << "Location: " << caminhao.getLocation().first << ", " << caminhao.getLocation().second << "\n"
       << "Model: " << caminhao.getModel() << "\n"
       << "Year of Production: " << caminhao.getYearProduction() << "\n";
    return os;
}