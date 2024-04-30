#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <vector>
#include "../coordinates/coordinates.hpp"

class Vehicle
{
private:
    int loadCapacity;
    int yearProduction;
    std::string chassis;
    std::string model;
    Coordinates coordinates; 
    float height;
    bool available;
public:
    Vehicle();
    Vehicle(int loadCapacity, int yearProduction, std::string chassis, std::string model, double latitude, double longitude, float height, bool available);
    ~Vehicle();

    int setLoadCapacity(int loadCapacity);
    int getLoadCapacity() const;

    int setYearProduction(int yearProduction);
    int getYearProduction() const;

    int setChassis(std::string chassis);
    std::string getChassis() const;

    void setLocation(double latitude, double longitude);
    Coordinates getLocation() const;

    int setModel(std::string model);
    std::string getModel() const;

    int setHeight(int height);
    float getHeight() const;

    int setAvailable(bool available);
    bool getAvailable() const;

    friend bool operator==(const Vehicle &lhs, const Vehicle &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Vehicle &vehicle);
};

#endif