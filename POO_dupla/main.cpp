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
    registerFile("dados_entregas.csv", "arquivo_limpo.csv");
    std::list<Order*>& allOrders = Order::get_instances();

}
