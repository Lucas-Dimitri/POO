#include <iostream>
#include <string>
#include "pedidos.h"
#include "client.h"

Pedidos::Pedidos(): cliente("", 0, "", ""), tipo_transporte(""), local_coleta(""), local_entrega(""), peso_carga(0), volume_carga("") {}
Pedidos::Pedidos(Client cliente, std::string tipo_transporte, std::string local_coleta, std::string local_entrega, int peso_carga, std::string volume_carga) :cliente(cliente), tipo_transporte(tipo_transporte), local_coleta(local_coleta), local_entrega(local_entrega), peso_carga(peso_carga), volume_carga(volume_carga) {}
Pedidos::~Pedidos(){}

//metodos de classe
int Pedidos::setCliente(Client cliente){ this->cliente = cliente; }
Client Pedidos::getCliente(){ return this->cliente; }

int Pedidos::setTipoTransporte(std::string tipo_transporte)
{
    for(char& c: tipo_transporte) c = tolower(c);
    if(tipo_transporte == "carro" || tipo_transporte == "caminhao" || tipo_transporte == "camionete")
    {
        this->tipo_transporte = tipo_transporte;
        return 1;
    }
    return 0;
}
std::string Pedidos::getTipoTransporte(){ return this->tipo_transporte; }

int Pedidos::setLocalColeta(std::string local_coleta)
{
    if (local_coleta.size() < 30)
    {
        this->local_coleta = local_coleta;
        return 1;
    }
    return 0;
}
std::string Pedidos::getLocalColeta(){ return this->local_coleta; }

int Pedidos::setLocalEntrega(std::string local_entrega)
{
    if (local_entrega.size() < 30)
    {
        this->local_entrega = local_entrega;
        return 1;
    }
    return 0;
}
std::string Pedidos::getLocalEntrega(){ return this->local_entrega; }

int Pedidos::setPeso(int peso_carga)
{
    if (peso_carga < 100000)
    {
        this->peso_carga = peso_carga;
        return 1;
    }
    return 0;
}
int Pedidos::getPeso(){ return this->peso_carga; }

int Pedidos::setVolumeCarga(std::string volume_carga)
{
    if (volume_carga.size() < 7)
    {
        this->volume_carga = volume_carga;
        return 1;
    }
    
}
std::string Pedidos::getVolumeCarga(){ return this->volume_carga; }