#include <iostream>
#include <string>
#include "vehicle.h"
#include "caminhao.h"

Caminhao::Caminhao() : Vehicle(), altura(0) {}
Caminhao::Caminhao(int capacidade_carga, int ano_fabricacao, std::string chassi, std::string modelo, std::string localizacao, int altura) : Vehicle(capacidade_carga, ano_fabricacao, chassi, modelo, localizacao), altura(altura) {}
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

int Caminhao::getAltura(){ return this->altura; }