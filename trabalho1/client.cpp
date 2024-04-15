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
std::string Client::getNome() const { return this->nome; }

int Client::setIdade(int idade)
{
    if(idade > 18) 
    {
        this->idade = idade;
        return 1;
    }
    return 0;
}
int Client::getIdade() const { return this->idade; }

int Client::setEndereco(std::string endereco){
    if (endereco.size() > 10)
    {
        this->endereco = endereco;
        return 1;
    }
    return 0;

}
std::string Client::getEndereco() const { return this->endereco; }

int Client::setCPF(std::string cpf)
{
    if (cpf.size() > 10)
    {
        this->cpf = cpf;
        return 1;
    }
    return 0;
}
std::string Client::getCPF() const { return this->cpf; }

bool operator==(const Client &lhs, const Client &rhs)
{
    return lhs.getCPF() == rhs.getCPF() &&
           lhs.getEndereco() == rhs.getEndereco() &&
           lhs.getIdade() == rhs.getIdade() &&
           lhs.getNome() == rhs.getNome();
}

std::ostream &operator<<(std::ostream &os, const Client &client)
{
    os << "Nome: " << client.getNome() << "\n"
       << "CPF: " << client.getCPF() << "\n"
       << "Endereco: " << client.getEndereco() << "\n"
       << "idade: " << client.getIdade() << "\n";
    return os;
}