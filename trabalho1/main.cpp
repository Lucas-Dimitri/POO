#include <iostream>
#include <string>
#include <random>
#include "reader/reader.h"

int main(){
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<double> dis( -10.6734214, 29.7875286);

    manageVehicle *manage_vehicle = new manageVehicle;
    Vehicle *vehicle;

    for (int i = 0; i < 5000; i++) {
        vehicle = new Vehicle(rand() % 200 + 400, 2020, "AUDBA382HC7281", "Qualquer", dis(gen), -55.768967, 1000, true);
        manage_vehicle->pushVehicle(vehicle);
    }


    Manager *manager = new Manager( manage_vehicle);

    std::vector<std::string> csv_data = Reader::read_csv("dados_entregas.csv");
    
    std::list<Client*> clients;

    for ( int i = 0; i < csv_data.size()/9; i++) {
        Client * client = new Client();
        
        client->setName(csv_data[0]);
        client->setAdress(csv_data[2]);
        

        try{
            // Converte as colunas 7 e 8 para inteiros
            
            int weight = std::stoi(csv_data[7]);
            int volume = std::stoi(csv_data[8]);

            bool isPriority = (csv_data[9] == "sim");

            // Cria o objeto Order com as informações
            Order *order = new Order(client, "Car", csv_data[5], csv_data[6], weight, volume, isPriority);
            clients.push_back(client);

            manager->addOrder(order);
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