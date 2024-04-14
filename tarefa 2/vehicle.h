// Vehicle.h
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <vector>

class Vehicle {
private:
    int capacidade_carga;
    int ano_fabricacao;
    std::string chassi;
    std::string modelo;
    std::string localizacao;

public:
    Vehicle();
    Vehicle(int capacidade_carga, int ano_fabricacao, std::string chassi, std::string modelo, std::string localizacao);
    ~Vehicle();

    static std::vector<Vehicle> vehicleList;

    static void pushVeiculo(int capacidade_carga, int ano_fabricacao, std::string chassi, std::string modelo, std::string localizacao);
    static void popVeiculo();
    static void buscarVeiculo(std::string chassi);

    int setCapacidade(int capacidade);
    int getCapacidade() const;

    int setAnoFabricacao(int fabricacao);
    int getAnoFabricacao() const;

    int setChassi(std::string chassi);
    std::string getChassi() const;

    int setModelo(std::string modelo);
    std::string getModelo() const;

    int setLocalizacao(std::string localizacao);
    std::string getLocalizacao() const;
};

#endif
