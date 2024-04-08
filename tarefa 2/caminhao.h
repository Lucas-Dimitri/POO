#ifndef CAMINHAO_H
#define CAMINHAO_H

#include "vehicle.h"
#include <string>

class Caminhao : public Vehicle
{
    public:
        Caminhao();
        ~Caminhao();
        
    private:
        int altura;
};

#endif