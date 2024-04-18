#include <iostream>
#include <string>
#include "client.h"

Client::Client(): name(""), age(0), adress(""), cpf("") {}
Client::Client(std::string name, int age, std::string adress, std::string cpf) :name(name), age(age), adress(adress), cpf(cpf) {}
Client::~Client(){}

int Client::setName(std::string name){
    if(name.size() > 3)
    {
        this -> name = name;
        return 1;
    }
    return 0;
}
std::string Client::getName() const { return this->name; }

int Client::setAge(int age)
{
    if(age > 18) 
    {
        this->age = age;
        return 1;
    }
    return 0;
}
int Client::getAge() const { return this->age; }

int Client::setAdress(std::string adress){
    if (adress.size() > 10)
    {
        this->adress = adress;
        return 1;
    }
    return 0;

}
std::string Client::getAdress() const { return this->adress; }

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
           lhs.getAdress() == rhs.getAdress() &&
           lhs.getAge() == rhs.getAge() &&
           lhs.getName() == rhs.getName();
}

std::ostream &operator<<(std::ostream &os, const Client &client)
{
    os << "Name: " << client.getName() << "\n"
       << "CPF: " << client.getCPF() << "\n"
       << "Adress: " << client.getAdress() << "\n"
       << "Age: " << client.getAge() << "\n";
    return os;
}