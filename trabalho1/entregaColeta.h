#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <vector>
#include "pedidos.h"

class EntregaColeta
{
private:
    Pedidos pedido;

public:

    int setCapacidade(int capacidade);
    int getCapacidade() const;
};

#endif