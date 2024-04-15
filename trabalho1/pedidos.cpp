#include <iostream>
#include <ostream>
#include <string>
#include "pedidos.h"
#include "client.h"


Pedidos::Pedidos() : cliente("", 0, "", ""), tipo_transporte(""), local_coleta(""), local_entrega(""), peso_carga(0), volume_carga("") {}

Pedidos::Pedidos(Client cliente, std::string tipo_transporte, std::string local_coleta, std::string local_entrega, int peso_carga, std::string volume_carga) : cliente(cliente), tipo_transporte(tipo_transporte), local_coleta(local_coleta), local_entrega(local_entrega), peso_carga(peso_carga), volume_carga(volume_carga) {}

Pedidos::~Pedidos() {}


void Pedidos::setCliente(Client cliente) { this->cliente = cliente; }
Client Pedidos::getCliente() const { return this->cliente; }

int Pedidos::setTipoTransporte(std::string tipo_transporte)
{
    for (char &c : tipo_transporte)
        c = tolower(c);
    if (tipo_transporte == "carro" || tipo_transporte == "caminhao" || tipo_transporte == "camionete")
    {
        this->tipo_transporte = tipo_transporte;
        return 1;
    }
    return 0;
}
std::string Pedidos::getTipoTransporte() const { return this->tipo_transporte; }

int Pedidos::setLocalColeta(std::string local_coleta)
{
    if (local_coleta.size() < 30)
    {
        this->local_coleta = local_coleta;
        return 1;
    }
    return 0;
}
std::string Pedidos::getLocalColeta() const { return this->local_coleta; }

int Pedidos::setLocalEntrega(std::string local_entrega)
{
    if (local_entrega.size() < 30)
    {
        this->local_entrega = local_entrega;
        return 1;
    }
    return 0;
}
std::string Pedidos::getLocalEntrega() const { return this->local_entrega; }

int Pedidos::setPeso(int peso_carga)
{
    if (peso_carga < 100000)
    {
        this->peso_carga = peso_carga;
        return 1;
    }
    return 0;
}
int Pedidos::getPeso() const { return this->peso_carga; }

int Pedidos::setVolumeCarga(std::string volume_carga)
{
    if (volume_carga.size() < 7)
    {
        this->volume_carga = volume_carga;
        return 1;
    }
    return 0;
}
std::string Pedidos::getVolumeCarga() const { return this->volume_carga; }

bool operator==(const Pedidos &lhs, const Pedidos &rhs)
{
    return lhs.getCliente() == rhs.getCliente() &&
           lhs.getLocalColeta() == rhs.getLocalColeta() &&
           lhs.getLocalEntrega() == rhs.getLocalEntrega() &&
           lhs.getPeso() == rhs.getPeso() &&
           lhs.getTipoTransporte() == rhs.getTipoTransporte() &&
           lhs.getVolumeCarga() == rhs.getVolumeCarga();
}

std::ostream &operator<<(std::ostream &os, const Pedidos &pedido)
{
    os << "Cliente: " << pedido.getCliente() << "\n"
       << "Local de coleta: " << pedido.getLocalColeta() << "\n"
       << "Local de Entrega: " << pedido.getLocalEntrega() << "\n"
       << "Peso: " << pedido.getPeso() << "\n"
       << "Tipo de transporte: " << pedido.getTipoTransporte() << "\n"
       << "Volume de Carga: " << pedido.getVolumeCarga() << "\n";
    return os;
}