#include "manager.hpp"
#include <iostream>

// Implementação dos métodos da classe Manager

Manager::Manager(manageVehicle *vehicles) {
    this->vehicles = vehicles;
}

bool Manager::fulfillOrder(Order *order, int quant) {
    int ld = order->getLoadWeight();
    int i = 1;
    int num_vehicles = 0;

    while (num_vehicles < quant && i > quant + num_vehicles) {
        Vehicle *vehicle = this->vehicles->search(ld / i, order->getCollectPoint());

        if (vehicle) {
            ld -= vehicle->getLoadCapacity();
            order->addVehicle(vehicle);
            num_vehicles++;
        } else {
            i++;
        }
    }

    if (num_vehicles > 0) {
        std::cout << "Pedido atendido\n";
        return true;
    } else {
        std::cout << "Pedido nao atendido\n";
        return false;
    }
}

void Manager::addOrder(Order *order) {
    if (order->isPriority()) {
        auto it = orders.begin();
        while (it != orders.end()) {
            if (!((*it)->isPriority())) {
                orders.insert(it, order);
                return;
            }
            ++it;
        }
    }
    orders.push_back(order);
}

void Manager::fulfillOrders() {
    auto it = orders.begin();
    while (it != orders.end()) {
        if (fulfillOrder(*it, 10)) {
            // Remover da lista e adicionar a orders_fulfilled
            orders_fulfilled.push_back(*it);
            it = orders.erase(it);
        } else {
            ++it;
        }
    }
}
