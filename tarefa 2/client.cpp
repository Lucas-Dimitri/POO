#include <iostream>
#include <string>
#include "client.h"

Client::Client(): nome(""), idade(0), endereco(""), cpf("") {}
Client::Client(std::string nome, int idade, std::string endereco, std::string cpf) :nome(nome), idade(idade), endereco(endereco), cpf(cpf) {}
Client::~Client(){}

int Client::setNome(std::string nome){
    if(nome.size() > 3)
    {
        this -> nome = nome;
        return 1;
    }
    return 0;
}
std::string Client::getNome(){ return this->nome; }

int Client::setIdade(int idade)
{
    if(idade > 18) 
    {
        this->idade = idade;
        return 1;
    }
    return 0;
}
int Client::getIdade(){ return this->idade; }

int Client::setEndereco(std::string endereco){
    if (endereco.size() > 10)
    {
        this->endereco = endereco;
        return 1;
    }
    return 0;

}
std::string Client::getEndereco(){ return this->endereco; }

int Client::setCPF(std::string cpf)
{
    if (cpf.size() > 10)
    {
        this->cpf = cpf;
        return 1;
    }
    return 0;
}
std::string Client::getCPF(){ return this->cpf; }