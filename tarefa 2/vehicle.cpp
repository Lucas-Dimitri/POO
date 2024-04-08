#include <iostream>
#include <string>
#include "vehicle.h"

Vehicle::Vehicle(): capacidade_carga(0), ano_fabricacao(0), chassi(""), modelo(""), localizacao("") {}
Vehicle::Vehicle(int capacidade_carga, int ano_fabricacao, std::string chassi, std::string modelo, std::string localizacao) :capacidade_carga(capacidade_carga), ano_fabricacao(ano_fabricacao), chassi(chassi), modelo(modelo), localizacao(localizacao) {}
Vehicle::~Vehicle(){}


int Vehicle::setCapacidade(int capacidade_carga)
{
    if (capacidade_carga > 10 && capacidade_carga < 1000000) this->capacidade_carga = capacidade_carga;
}
int Vehicle::getCapacidade(){ return this->capacidade_carga; }

int Vehicle::setAnoFabricacao(int fabricacao)
{
    if (fabricacao > 1884 && fabricacao < 2026)
    {
        this->ano_fabricacao = fabricacao;
        return 1;
    }
    
    return 0;
}
int Vehicle::getAnoFabricacao(){ return this->ano_fabricacao; }

int Vehicle::setChassi(std::string chassi)
{
    if (chassi.size() == 17)
    {
        this->chassi = chassi;
        return 1;
    }
    return 0;
}
std::string Vehicle::getChassi(){ return this->chassi; }

int Vehicle::setModelo(std::string modelo)
{
    if (modelo.size() < 20)
    {
        this->modelo = modelo;
        return 1;
    }
    return 0;
}
std::string Vehicle::getModelo(){ return this->modelo; }

int Vehicle::setLocalizacao(std::string localizacao)
{
    if (localizacao.size() > 10)
    {
        this->localizacao = localizacao;
        return 1;
    }
    return 0;
}
std::string Vehicle::getLocalizacao(){ return this->localizacao; }
