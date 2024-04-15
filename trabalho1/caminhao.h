#ifndef CAMINHAO_H
#define CAMINHAO_H

#include "vehicle.h"
#include <string>

class Caminhao : public Vehicle
{
    public:
        Caminhao();
        Caminhao(int capacidade_carga, int ano_fabricacao, std::string chassi, std::string modelo,int latitude, int longitude, int altura);
        ~Caminhao();
        int setAltura(int altura);
        int getAltura() const;

        friend bool operator==(const Caminhao &lhs, const Caminhao &rhs);
        friend std::ostream &operator<<(std::ostream &os, const Caminhao &caminhao);

    private:
        int altura;
};

#endif