#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle
{
    protected:
        int capacidade_carga;
        int ano_fabricacao;
        std::string chassi;
        std::string modelo;
        std::string localizacao;

    public:
        //constructor
        Vehicle();
        Vehicle(int capacidade_carga, int ano_fabricacao, std::string chassi, std::string modelo, std::string localizacao);
        ~Vehicle();
        
        //metodos de classe

        int setCapacidade(int capacidade);
        int getCapacidade();

        int setAnoFabricacao(int fabricacao);
        int getAnoFabricacao();

        int setChassi(std::string chassi);
        std::string getChassi();

        int setModelo(std::string modelo);
        std::string getModelo();

        int setLocalizacao(std::string localizacao);
        std::string getLocalizacao();
};

#endif