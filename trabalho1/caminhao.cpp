#include <iostream>
#include <string>
#include "vehicle.h"
#include "caminhao.h"

Caminhao::Caminhao() : Vehicle(), altura(0) {}
Caminhao::Caminhao(int capacidade_carga, int ano_fabricacao, std::string chassi, std::string modelo, int latitude, int longitude, int altura) : Vehicle(capacidade_carga, ano_fabricacao, chassi, modelo, latitude, longitude), altura(altura) {}
Caminhao::~Caminhao(){}

int Caminhao::setAltura(int altura)
{
    if (altura < 10)
    {
        this->altura = altura;
        return 1;
    }
    return 0;   
}

int Caminhao::getAltura() const { return this->altura; }

bool operator==(const Caminhao &lhs, const Caminhao &rhs)
{
    return lhs.getAltura() == rhs.getAltura() &&
           lhs.getAnoFabricacao() == rhs.getAnoFabricacao() &&
           lhs.getCapacidade() == rhs.getCapacidade() &&
           lhs.getChassi() == rhs.getChassi() &&
           lhs.getLocalizacao() == rhs.getLocalizacao() &&
           lhs.getModelo() == rhs.getModelo();
}

std::ostream &operator<<(std::ostream &os, const Caminhao &caminhao)
{
    os << "Altura: " << caminhao.getAltura() << "\n"
       << "Capacidade: " << caminhao.getCapacidade() << "\n"
       << "Chassi: " << caminhao.getChassi() << "\n"
       << "Localizacao: " << caminhao.getLocalizacao().first << ", " << caminhao.getLocalizacao().second << "\n"
       << "Modelo: " << caminhao.getModelo() << "\n"
       << "Ano de fabricacao: " << caminhao.getAnoFabricacao() << "\n";
    return os;
}