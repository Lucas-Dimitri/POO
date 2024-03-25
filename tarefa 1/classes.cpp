#include <iostream>
#include <string>
#include <list>

using namespace std;

class Vehicle
{
    private:
        //atributos de classe
        string tipo;
        int capacidade_carga;
        int ano_fabricacao;
        string chassi;
        string modelo;
        string localizacao;

    public:
        //metodos de classe
        void setTipo(string tipo)
        {
            for(char& c: tipo) c = tolower(c);
            if(tipo == "carro" || tipo == "caminhao" || tipo == "camionete") this-> tipo = tipo;
        }
        string getTipo(){ return this->tipo; }

        void setCapacidade(int capacidade) { this->capacidade_carga = capacidade; }
        int getCapacidade(){ return this->capacidade_carga; }

        void setAnoFabricacao(int fabricacao){ this->ano_fabricacao = fabricacao; }
        int getAnoFabricacao(){ return this->ano_fabricacao; }

        void setChassi(string chassi){ this->chassi = chassi; }
        string getChassi(){ return this->chassi; }

        void setModelo(string modelo){ this->modelo = modelo; }
        string getModelo(){ return this->modelo; }

        void setLocalizacao(string localizacao){ this->localizacao = localizacao; }
        string getLocalizacao(){ return this->localizacao; }
};

class Clientes
{
    private:
        //atributos de classe
        string nome;
        int idade;
        string endereco;
        string cpf;

    public:
        //metodos de classe

        Clientes(string nome, int idade, string endereco, string cpf) :nome(nome), idade(idade), endereco(endereco), cpf(cpf) {}

        // Default constructor
        Clientes() : nome(""), idade(0), endereco(""), cpf("") {}

        void setNome(string nome){ this->nome = nome; }
        string getNome(){ return this->nome; }

        void setIdade(int idade) { if(idade > 18) this->idade = idade; }
        int getIdade(){ return this->idade; }

        void setEndereco(string endereco){ this->endereco = endereco; }
        string getEndereco(){ return this->endereco; }

        void setCPF(string cpf){ this->cpf = cpf; }
        string getCPF(){ return this->cpf; }

};

class Pedidos
{
    private:
        //atributos de classe
        Clientes cliente;
        string tipo_transporte;
        string local_coleta;
        string local_entrega;
        int peso_carga;
        string volume_carga;

    public:
        //metodos de classe
        void setCliente(Clientes cliente){ this->cliente = cliente; }
        Clientes getCliente(){ return this->cliente; }

        void setTipoTransporte(string transporte){ this->tipo_transporte = transporte; }
        string getTipoTransporte(){ return this->tipo_transporte; }

        void setLocalColeta(string local_coleta){ this->local_coleta = local_coleta; }
        string getLocalColeta(){ return this->local_coleta; }

        void setLocalEntrega(string local_entrega){ this->local_entrega = local_entrega; }
        string getLocalEntrega(){ return this->local_entrega; }

        void setPeso(int peso){ this->peso_carga = peso; }
        int getPeso(){ return this->peso_carga; }

        void setVolumeCarga(string volume){ this->volume_carga = volume; }
        string getVolumeCarga(){ return this->volume_carga; }
};

int main()
{
    Vehicle carro1;
    carro1.setAnoFabricacao(2019);
    carro1.setCapacidade(1542);
    carro1.setChassi("9BD111060T5002156");
    carro1.setLocalizacao("Florida, EUA");
    carro1.setModelo("Toyota Supra");
    carro1.setTipo("CarrO");
    

    cout << carro1.getModelo() << "\n" << carro1.getTipo() << "\n";

    Clientes cliente1("Glauber", 38, "Rua 123, 321", "000.111.222-3");

    cout << cliente1.getCPF() << "\n";

    Pedidos *pedido1 = new Pedidos;
    pedido1->setCliente(cliente1);
    pedido1->setLocalColeta("Rua 123");
    pedido1->setLocalEntrega("Rua 321");
    pedido1->setPeso(1345);
    pedido1->setTipoTransporte("carro");
    pedido1->setVolumeCarga("10x10x10");

    cout << pedido1->getLocalColeta() << "\n";

    pedido1->setLocalColeta("Rua 123123");

    cout << pedido1->getLocalColeta() << "\n";

}