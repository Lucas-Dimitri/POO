#include "vehicle.h"
#include <iostream>
#include <string>

Vehicle::Vehicle(): loadCapacity(0), yearProduction(0), chassis(""), model(""), coordinates(0, 0), height(0), available(true) {}

Vehicle::Vehicle(int loadCapacity, int yearProduction, std::string chassis, std::string model, double latitude, double longitude, float height, bool available) {
    // ADICIONANDO VERIFICADORES NO CONSTRUTOR 
    if( loadCapacity > 0){
        this->loadCapacity = loadCapacity;
    }
    else{
        throw std::invalid_argument("Valor invalido para capacidade\n");
    }
    coordinates.set_coordinates(latitude, longitude);

} 
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

void Vehicle::setLocation(double latitude, double longitude)
{
    this->coordinates.set_coordinates(latitude, longitude);
}
Coordinates Vehicle::getLocation() const
{
    return this->coordinates;
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

int Vehicle::setHeight(int height)
{
    if (height < 10)
    {
        this->height = height;
        return 1;
    }
    return 0;
}

float Vehicle::getHeight() const { return this->height; }

int Vehicle::setAvailable(bool available)
{
    this->available = available;
    return 1;
}
bool Vehicle::getAvailable() const { return this->available; }

    bool operator==(const Vehicle &lhs, const Vehicle &rhs)
{
    return lhs.getYearProduction() == rhs.getYearProduction() &&
           lhs.getLoadCapacity() == rhs.getLoadCapacity() &&
           lhs.getChassis() == rhs.getChassis() &&
           lhs.getLocation() == rhs.getLocation() &&
           lhs.getModel() == rhs.getModel() &&
           lhs.getHeight() == rhs.getHeight();
}

std::ostream &operator<<(std::ostream &os, const Vehicle &vehicle)
{
    os << "Year of production: " << vehicle.getYearProduction() << "\n"
       << "Load capacity: " << vehicle.getLoadCapacity() << "\n"
       << "Chassis: " << vehicle.getChassis() << "\n"
       << "Location: " << vehicle.getLocation() << "\n"
       << "Model: " << vehicle.getModel() << "\n"
       << "Vehicle height: " << vehicle.getHeight() << "\n";
    return os;
}