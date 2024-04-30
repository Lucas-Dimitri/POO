#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "../orders/order.h"
#include "../vehicles/manageVehicle.h"
#include <list>

class Manager {
private:
    manageVehicle *vehicles;
    std::list<Order*> orders;
    std::list<Order*> orders_fulfilled;

    bool fulfillOrder(Order *order, int quant);

public:
    Manager(manageVehicle *vehicles);
    void addOrder(Order *order);
    void fulfillOrders();
};

#endif // MANAGER_HPP
