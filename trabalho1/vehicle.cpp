#include "vehicle.h"
#include <iostream>
#include <string>

Vehicle::Vehicle(): loadCapacity(0), yearProduction(0), chassis(""), model(""), latitude(0), longitude(0) {}

Vehicle::Vehicle(int loadCapacity, int yearProduction, std::string chassis, std::string model, int latitude, int longitude)
    : loadCapacity(loadCapacity), yearProduction(yearProduction), chassis(chassis), model(model), latitude(latitude), longitude(longitude) {}

Vehicle::~Vehicle() {}

int Vehicle::setYearProduction(int yearProduction)
{
    if (yearProduction > 1884 && yearProduction < 2026)
    {
        this->yearProduction = yearProduction;
        return 1;
    }
    return 0;
}
int Vehicle::getYearProduction() const { return this->yearProduction; }

int Vehicle::setLoadCapacity(int loadCapacity)
{
    if (loadCapacity > 10 && loadCapacity < 1000000)
    {
        this->loadCapacity = loadCapacity;
        return 1;
    }
    return 0;
}
int Vehicle::getLoadCapacity() const { return this->loadCapacity; }

int Vehicle::setChassis(std::string chassis)
{
    if (chassis.size() == 17)
    {
        this->chassis = chassis;
        return 1;
    }
    return 0;
}
std::string Vehicle::getChassis() const { return this->chassis; }

void Vehicle::setLocation(int latitude, int longitude)
{
    this->latitude = latitude;
    this->longitude = longitude;
}
std::pair<int, int> Vehicle::getLocation() const
{
    return std::make_pair(latitude, longitude);
}

int Vehicle::setModel(std::string model)
{
    if (model.size() < 20)
    {
        this->model = model;
        return 1;
    }
    return 0;
}
std::string Vehicle::getModel() const { return this->model; }

bool operator==(const Vehicle &lhs, const Vehicle &rhs)
{
    return lhs.getYearProduction() == rhs.getYearProduction() &&
           lhs.getLoadCapacity() == rhs.getLoadCapacity() &&
           lhs.getChassis() == rhs.getChassis() &&
           lhs.getLocation() == rhs.getLocation() &&
           lhs.getModel() == rhs.getModel();
}

std::ostream &operator<<(std::ostream &os, const Vehicle &vehicle)
{
    os << "Year of production: " << vehicle.getYearProduction() << "\n"
       << "Load capacity: " << vehicle.getLoadCapacity() << "\n"
       << "Chassis: " << vehicle.getChassis() << "\n"
       << "Location: " << vehicle.getLocation().first << ", " << vehicle.getLocation().second << "\n"
       << "Model: " << vehicle.getModel() << "\n";
    return os;
}