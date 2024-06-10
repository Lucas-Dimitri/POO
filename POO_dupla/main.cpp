#include<iostream>
#include"include/Garage.hpp"
#include"include/Order.hpp"
#include"include/Car.hpp"
#include"include/Pickup.hpp"
#include"include/Truck.hpp"
#include"include/Client.hpp"
#include "include/Manager.hpp"
#include "include/Instantiate.hpp"
#include "include/Vehicle.hpp"

int main()
{
    Garage *garagem = new Garage(-13.0, 13.0);

    Car *uno = new Car("JAY-0000", "9BWHE21JX24060831", "Uno", 10, 2010, -13.0, 13.0);
    Car *prisma = new Car("MNS-0000", "9BWHE21JX24060831", "Prisma", 10, 2010, -13.0, 13.0);
    std::cout << *uno;

    std::cout << *garagem << '\n';

    garagem->add_vehicle(prisma);
    garagem->add_vehicle(uno);

    std::cout << *garagem << '\n';

    Client *cliente = new Client("osvaldo", "333.222.333-12", "rua 123", "55-4444-4444", "osvaldo@hotmail.com");

    Order *order = new Order(0, Coordinates(10.0, 12.1), Coordinates(10.0, 10.1), 5, 10, true);

    Order *order2 = new Order(0, Coordinates(10.0, 12.1), Coordinates(10.0, 10.1), 5, 4, true);
    Manager *adm = new Manager(garagem);

    adm->add_order(order);
    adm->add_order(order2);
    adm->fulfill_orders(true);

    return 0;
}
