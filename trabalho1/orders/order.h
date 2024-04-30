#ifndef order_H
#define order_H
#include <string>
#include <vector>
#include "../clients/client.h"
#include "../vehicles/truck.h"
#include <list>

class Order
{
    private:
        Client *client;
        std::string transportationType;
        std::string collectPoint;
        std::string dropoffLocation;
        int loadWeight;
        int loadVolume;
        std::list<Vehicle*> vehicles;
        bool priority;


    public:
        //metodos de classe

        Order();
        Order(Client *client, std::string transportationType, std::string collectPoint ,std::string dropoffLocation, int loadWeight, int loadVolume, bool p = false);
        ~Order();

        void setClient(Client *client);
        Client* getClient() const;

        int setTransportationType(std::string transportationType);
        std::string getTransportationType() const;

        int setCollectPoint( std::string collectPoint);
        std::string getCollectPoint()const;

        int setDropoffLocation(std::string dropoffLocation);
        std::string getDropoffLocation() const;

        int setLoadWeight(int weight);
        int getLoadWeight() const;

        int setLoadVolume(int volume);
        int getLoadVolume() const;

        void addVehicle( Vehicle *vehicle);
        void removeVehicle( Vehicle *vehicle);

        bool isPriority();

        friend bool operator==(const Order& lhs, const Order& rhs);
        friend std::ostream& operator<<(std::ostream& os, const Order& Order);
};

#endif