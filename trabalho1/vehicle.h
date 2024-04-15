#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <vector>

class Vehicle
{
private:
    int capacidade_carga;
    int ano_fabricacao;
    std::string chassi;
    std::string modelo;
    int latitude;  // Latitude coordinate
    int longitude; // Longitude coordinate

public:
    Vehicle();
    Vehicle(int capacidade_carga, int ano_fabricacao, std::string chassi, std::string modelo, int latitude, int longitude);
    ~Vehicle();

    int setCapacidade(int capacidade);
    int getCapacidade() const;

    int setAnoFabricacao(int fabricacao);
    int getAnoFabricacao() const;

    int setChassi(std::string chassi);
    std::string getChassi() const;

    void setLocalizacao(int latitude, int longitude);
    std::pair<int, int> getLocalizacao() const;

    int setModelo(std::string modelo);
    std::string getModelo() const;

    friend bool operator==(const Vehicle &lhs, const Vehicle &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Vehicle &vehicle);
};

#endif