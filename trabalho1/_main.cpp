#include <iostream>
#include <string>
#include <vector>
#include "client.h"
#include "order.h"
#include "vehicle.h"
#include "truck.h"
#include "transportation.h"
#include "manageVehicle.h"


int main()
{
    Client client1("Glauber", 38, "Rua 123, 321", "000.111.222-3");

    Order order1(client1, "carro", "Rua 123", "rua 321", 100, "300 litros");

    Truck *truck1 = new Truck(100, 2000, "11111111111111111", "focus", 3, 3, 3, true);
    Truck truck2 = Truck(100, 2000, "11111111111111111", "focus", 3, 3, 3, true);
    Vehicle vehicle1 = Vehicle(100, 2000, "12312312312312312", "prisma", 3, 3, 3.4, true);

    manageVehicle::pushVehicle(vehicle1);
    manageVehicle::pushVehicle(truck2);


    Vehicle vehicle2 = manageVehicle::searchVehicle("12312312312312312");
    std::cout << vehicle2 << "\n";

    if (vehicle1 == vehicle2) printf("Equals\n");
    else printf("Not equals\n");

    if (*truck1 == truck2) printf("Equals\n");
    else
        printf("Not equals\n");

    std::cout << truck1;

    delete(truck1);

    return 0;
}