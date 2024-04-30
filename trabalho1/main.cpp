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

    manageVehicle *manage_vehicle;


    Vehicle *uno = new Vehicle( 400, 2012, "AUDBA382HC7281", "Uno", 29.7875286, -55.768967, 1000, true);

    for (int i = 0; i < 100; i++) {
        Vehicle *vehicle = new Vehicle(rand() % 200 + 400, 2020, "AUDBA382HC7281", "Qualquer", dis(gen), -55.768967, 1000, true);
        manage_vehicle->vehicleList.push_back(vehicle);
    }


    Manager *manager = new Manager( manage_vehicle);

    std::vector<std::vector<std::string>> csv_data = read_csv("dados_entregas.csv");
    

    for (int i = 1; i < csv_data.size(); i++) {
        Client *client = new Client();
        client->setName(csv_data[i][0]);
        client->setAdress(csv_data[i][2]);

        // Converte as colunas 7 e 8 para inteiros
        int origin = std::stoi(csv_data[i][7]);
        int destination = std::stoi(csv_data[i][8]);

        bool isPriority = (csv_data[i][9] == "sim");

        // Cria o objeto Order com as informações
        Order *order = new Order(client, "Car", csv_data[i][5], csv_data[i][6], origin, destination, isPriority);

        std::cout << "Foi\n";
        manager->addOrder(order);
    }
    
    manager->fulfillOrders();

    

    return 0;
}