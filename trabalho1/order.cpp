#include <iostream>
#include <ostream>
#include <string>
#include "order.h"
#include "client.h"


Order::Order() : client("", 0, "", ""), transportationType(""), pickupLocation(""), dropoffLocation(""), loadWeight(0), loadVolume("") {}

Order::Order(Client client, std::string transportationType, std::string pickupLocation, std::string dropoffLocation, int loadWeight, std::string loadVolume) : client(client), transportationType(transportationType), pickupLocation(pickupLocation), dropoffLocation(dropoffLocation), loadWeight(loadWeight), loadVolume(loadVolume) {}

Order::~Order() {}


void Order::setClient(Client client) { this->client = client; }
Client Order::getClient() const { return this->client; }

int Order::setTransportationType(std::string transportationType)
{
    for (char &c : transportationType)
        c = tolower(c);
    if (transportationType == "carro" || transportationType == "caminhao" || transportationType == "camionete")
    {
        this->transportationType = transportationType;
        return 1;
    }
    return 0;
}
std::string Order::getTransportationType() const { return this->transportationType; }

int Order::setPickupLocation(std::string pickupLocation)
{
    if (pickupLocation.size() < 30)
    {
        this->pickupLocation = pickupLocation;
        return 1;
    }
    return 0;
}
std::string Order::getPickupLocation() const { return this->pickupLocation; }

int Order::setDropoffLocation(std::string dropoffLocation)
{
    if (dropoffLocation.size() < 30)
    {
        this->dropoffLocation = dropoffLocation;
        return 1;
    }
    return 0;
}
std::string Order::getDropoffLocation() const { return this->dropoffLocation; }

int Order::setLoadWeight(int loadWeight)
{
    if (loadWeight < 100000)
    {
        this->loadWeight = loadWeight;
        return 1;
    }
    return 0;
}
int Order::getLoadWeight() const { return this->loadWeight; }

int Order::setLoadVolume(std::string loadVolume)
{
    if (loadVolume.size() < 7)
    {
        this->loadVolume = loadVolume;
        return 1;
    }
    return 0;
}
std::string Order::getLoadVolume() const { return this->loadVolume; }

bool operator==(const Order &lhs, const Order &rhs)
{
    return lhs.getClient() == rhs.getClient() &&
           lhs.getPickupLocation() == rhs.getPickupLocation() &&
           lhs.getDropoffLocation() == rhs.getDropoffLocation() &&
           lhs.getLoadWeight() == rhs.getLoadWeight() &&
           lhs.getTransportationType() == rhs.getTransportationType() &&
           lhs.getLoadVolume() == rhs.getLoadVolume();
}

std::ostream &operator<<(std::ostream &os, const Order &pedido)
{
    os << "Client: " << pedido.getClient() << "\n"
       << "Pick up Location: " << pedido.getPickupLocation() << "\n"
       << "Drop-off location: " << pedido.getDropoffLocation() << "\n"
       << "Load Weight: " << pedido.getLoadWeight() << "\n"
       << "Transportation type: " << pedido.getTransportationType() << "\n"
       << "Load Volume: " << pedido.getLoadVolume() << "\n";
    return os;
}