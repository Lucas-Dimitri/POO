#ifndef order_H
#define order_H
#include <string>
#include "client.h"

class Order
{
    private:
        Client client;
        std::string transportationType;
        std::string pickupLocation;
        std::string dropoffLocation;
        int loadWeight;
        int loadVolume;

    public:
        //metodos de classe

        Order();
        Order(Client client, std::string transportationType, std::string pickupLocation, std::string dropoffLocation, int loadWeight, int loadVolume);
        ~Order();

        void setClient(Client client);
        Client getClient() const;

        int setTransportationType(std::string transportationType);
        std::string getTransportationType() const;

        int setPickupLocation(std::string pickupLocation);
        std::string getPickupLocation() const;

        int setDropoffLocation(std::string dropoffLocation);
        std::string getDropoffLocation() const;

        int setLoadWeight(int weight);
        int getLoadWeight() const;

        int setLoadVolume(int volume);
        int getLoadVolume() const;

        friend bool operator==(const Order& lhs, const Order& rhs);
        friend std::ostream& operator<<(std::ostream& os, const Order& Order);
};

#endif