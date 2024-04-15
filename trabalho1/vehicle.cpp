#include "vehicle.h"
#include <iostream>
#include <string>

Vehicle::Vehicle(): capacidade_carga(0), ano_fabricacao(0), chassi(""), modelo(""), latitude(0), longitude(0) {}

Vehicle::Vehicle(int capacidade_carga, int ano_fabricacao, std::string chassi, std::string modelo, int latitude, int longitude)
    : capacidade_carga(capacidade_carga), ano_fabricacao(ano_fabricacao), chassi(chassi), modelo(modelo), latitude(latitude), longitude(longitude) {}

Vehicle::~Vehicle() {}

int Vehicle::setAnoFabricacao(int fabricacao)
{
    if (fabricacao > 1884 && fabricacao < 2026)
    {
        this->ano_fabricacao = fabricacao;
        return 1;
    }
    return 0;
}
int Vehicle::getAnoFabricacao() const { return this->ano_fabricacao; }

int Vehicle::setCapacidade(int capacidade_carga)
{
    if (capacidade_carga > 10 && capacidade_carga < 1000000)
    {
        this->capacidade_carga = capacidade_carga;
        return 1;
    }
    return 0;
}
int Vehicle::getCapacidade() const { return this->capacidade_carga; }

int Vehicle::setChassi(std::string chassi)
{
    if (chassi.size() == 17)
    {
        this->chassi = chassi;
        return 1;
    }
    return 0;
}
std::string Vehicle::getChassi() const { return this->chassi; }

void Vehicle::setLocalizacao(int latitude, int longitude)
{
    this->latitude = latitude;
    this->longitude = longitude;
}
std::pair<int, int> Vehicle::getLocalizacao() const
{
    return std::make_pair(latitude, longitude);
}

int Vehicle::setModelo(std::string modelo)
{
    if (modelo.size() < 20)
    {
        this->modelo = modelo;
        return 1;
    }
    return 0;
}
std::string Vehicle::getModelo() const { return this->modelo; }

bool operator==(const Vehicle &lhs, const Vehicle &rhs)
{
    return lhs.getAnoFabricacao() == rhs.getAnoFabricacao() &&
           lhs.getCapacidade() == rhs.getCapacidade() &&
           lhs.getChassi() == rhs.getChassi() &&
           lhs.getLocalizacao() == rhs.getLocalizacao() &&
           lhs.getModelo() == rhs.getModelo();
}

std::ostream &operator<<(std::ostream &os, const Vehicle &vehicle)
{
    os << "Ano de fabricacao: " << vehicle.getAnoFabricacao() << "\n"
       << "Capacidade: " << vehicle.getCapacidade() << "\n"
       << "Chassi: " << vehicle.getChassi() << "\n"
       << "Localizacao: " << vehicle.getLocalizacao().first << ", " << vehicle.getLocalizacao().second << "\n"
       << "Modelo: " << vehicle.getModelo() << "\n";
    return os;
}