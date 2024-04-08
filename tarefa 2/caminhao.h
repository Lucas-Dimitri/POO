#ifndef CAMINHAO_H
#define CAMINHAO_H

#include "vehicle.h"
#include <string>

class Caminhao : public Vehicle
{
    public:
        Caminhao();
        Caminhao(int capacidade_carga, int ano_fabricacao, std::string chassi, std::string modelo, std::string localizacao, int altura);
        ~Caminhao();
        int setAltura(int altura);
        int getAltura();
        
    private:
        int altura;
};

#endif