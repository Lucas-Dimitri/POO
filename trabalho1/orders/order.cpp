#include <iostream>
#include <ostream>
#include <string>
#include "order.h"


Order::Order() : client(nullptr), transportationType(""), collectPoint(""), dropoffLocation(""), loadWeight(0), loadVolume(0), priority(false){}

Order::Order(Client *client, std::string transportationType, std::string collectPoint ,std::string dropoffLocation, int loadWeight, int loadVolume, bool p) : client(client), transportationType(transportationType), collectPoint(collectPoint), dropoffLocation(dropoffLocation), loadWeight(loadWeight), loadVolume(loadVolume), priority( p) {}

Order::~Order() {
    for ( Vehicle *vehicle : vehicles){
        vehicle->setAvailable( true);
    }
    vehicles.clear();
}


void Order::setClient(Client *client) { this->client = client; }
Client* Order::getClient() const { return this->client; }

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

int Order::setDropoffLocation(std::string dropoffLocation)
{
    if (dropoffLocation.size() < 50)
    {
        this->dropoffLocation = dropoffLocation;
        return 1;
    }
    return 0;
}
std::string Order::getDropoffLocation() const { return this->dropoffLocation; }

int Order::setCollectPoint( std::string collectPoint){
    this->collectPoint = collectPoint;
    return 1;
}
std::string Order::getCollectPoint() const{
    return this->collectPoint;
}
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

int Order::setLoadVolume(int loadVolume)
{
    if (loadVolume < 7)
    {
        this->loadVolume = loadVolume;
        return 1;
    }
    return 0;
}
int Order::getLoadVolume() const { return this->loadVolume; }




bool Order::isPriority(){ return this->priority;}

void Order::addVehicle( Vehicle *vehicle){
    vehicles.push_back( vehicle);
    vehicle->setAvailable(false);
}

void Order::removeVehicle( Vehicle *vehicle){
}



bool operator==(const Order &lhs, const Order &rhs)
{
    return lhs.getClient() == rhs.getClient() &&
           lhs.getDropoffLocation() == rhs.getDropoffLocation() &&
           lhs.getLoadWeight() == rhs.getLoadWeight() &&
           lhs.getTransportationType() == rhs.getTransportationType() &&
           lhs.getLoadVolume() == rhs.getLoadVolume();
}

std::ostream &operator<<(std::ostream &os, const Order &pedido)
{
    os << "Client: " << pedido.getClient() << "\n"
       << "Drop-off location: " << pedido.getDropoffLocation() << "\n"
       << "Load Weight: " << pedido.getLoadWeight() << "\n"
       << "Transportation type: " << pedido.getTransportationType() << "\n"
       << "Load Volume: " << pedido.getLoadVolume() << "\n";
    return os;
}