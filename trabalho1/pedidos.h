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
        Client getCliente() const;

        int setTipoTransporte(std::string transporte);
        std::string getTipoTransporte() const;

        int setLocalColeta(std::string local_coleta);
        std::string getLocalColeta() const;

        int setLocalEntrega(std::string local_entrega);
        std::string getLocalEntrega() const;

        int setPeso(int peso);
        int getPeso() const;

        int setVolumeCarga(std::string volume);
        std::string getVolumeCarga() const;

        friend bool operator==(const Pedidos& lhs, const Pedidos& rhs);
        friend std::ostream& operator<<(std::ostream& os, const Pedidos& pedidos);
};

#endif