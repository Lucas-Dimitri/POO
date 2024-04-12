#ifndef PEDIDOS_H
#define PEDIDOS_H
#include <string>
#include "client.h"

class Pedidos
{
    private:
        Client cliente;
        std::string tipo_transporte;
        std::string local_coleta;
        std::string local_entrega;
        int peso_carga;
        std::string volume_carga;

    public:
        //metodos de classe

        Pedidos();
        Pedidos(Client cliente, std::string tipo_transporte, std::string local_coleta, std::string local_entrega, int peso_carga, std::string volume_carga);
        ~Pedidos();

        void setCliente(Client cliente);
        Client getCliente();

        int setTipoTransporte(std::string transporte);
        std::string getTipoTransporte();

        int setLocalColeta(std::string local_coleta);
        std::string getLocalColeta();

        int setLocalEntrega(std::string local_entrega);
        std::string getLocalEntrega();

        int setPeso(int peso);
        int getPeso();

        int setVolumeCarga(std::string volume);
        std::string getVolumeCarga();
};

#endif