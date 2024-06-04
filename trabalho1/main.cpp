#include <iostream>
#include <string>
#include <random>
#include "reader/reader.h"

int main(){

    Reader reader;
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<double> dis( -10.6734214, 29.7875286);

    manageVehicle *manage_vehicle = new manageVehicle;
    Vehicle **vehicle = new Vehicle*[100];

    for (int i = 0; i < 100; i++) {
        vehicle[i] = new Vehicle(rand() % 200 + 400, 2020, "AUDBA382HC7281", "Qualquer", dis(gen), -55.768967, 1000, true);
        manage_vehicle->pushVehicle(vehicle[i]);
    }


    Manager *manager = new Manager( manage_vehicle);

    std::vector<std::vector<std::string>> csv_data = reader.read_csv("dados_entregas.csv");
    
    std::list<Client*> clients;

    for (const auto& row : csv_data) {
        Client * client = new Client();
        std::cout << row.size();
        client->setName(row[0]);
        client->setAdress(row[2]);
        

        try{
            // Converte as colunas 7 e 8 para inteiros
            
            int weight = std::stoi(row[7]);
            int volume = std::stoi(row[8]);

            bool isPriority = (row[9] == "sim");

            std::cout << "Foi \n";
            // Cria o objeto Order com as informações
            Order *order = new Order(client, "Car", row[5], row[6], weight, volume, isPriority);
            clients.push_back(client);
        }
        catch ( const std::invalid_argument& e){
            std::cerr << "Erro nos parametros " << std::endl;
        }
        catch (const std::out_of_range &e){
            std::cerr << "Indice invalido" << std::endl;
        }
        
    }
    
    manager->fulfillOrders();

    return 0;
}