#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <random>

#include "clients/client.h"
#include "orders/order.h"
#include "vehicles/vehicle.h"
#include "vehicles/truck.h"
#include "manager/manager.hpp"
#include "vehicles/manageVehicle.h"

std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<std::vector<std::string>> read_csv(const std::string &filename) {
    std::ifstream file(filename);
    std::vector<std::vector<std::string>> lines;
    
    if (!file.is_open()) {
        std::cerr << "Erro ao ler o arquivo " << filename << std::endl;
        return lines; // Retorna um vetor vazio se houver erro ao abrir o arquivo
    }

    std::string line;

    
    while (std::getline(file, line)) {
        // Dividir a linha em campos usando a vírgula como delimitador
        std::vector<std::string> fields = split(line, ',');
        lines.push_back(fields);
    }

    // Fechar o arquivo
    file.close();
    
    return lines;
}


int main(){
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<double> dis( -10.6734214, 29.7875286);

    manageVehicle *manage_vehicle = new manageVehicle;
    Vehicle **vehicle = new Vehicle*[100];

    for (int i = 0; i < 100; i++) {
        vehicle[i] = new Vehicle(rand() % 200 + 400, 2020, "AUDBA382HC7281", "Qualquer", dis(gen), -55.768967, 1000, true);
        manage_vehicle->vehicleList.push_back(vehicle[i]);
    }


    Manager *manager = new Manager( manage_vehicle);

    std::vector<std::vector<std::string>> csv_data = read_csv("dados_entregas.csv");
    

    for (const auto& row : csv_data) {
        
        Client *client = new Client();
        client->setName(row[0]);
        client->setAdress(row[2]);

        // Converte as colunas 7 e 8 para inteiros
        int origin = std::stoi(row[7]);
        int destination = std::stoi(row[8]);

        bool isPriority = (row[9] == "sim");

        // Cria o objeto Order com as informações
        Order *order = new Order(client, "Car", row[5], row[6], origin, destination, isPriority);

        
        manager->addOrder(order);
    }
    
    manager->fulfillOrders();

    

    return 0;
}