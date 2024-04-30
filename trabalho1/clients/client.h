#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <ostream>
#include <iostream>

class Client
{
    private:
        std::string name;
        int age;
        std::string adress;
        std::string cpf;

    public:

        Client();
        Client(std::string name, std::string adress, std::string cpf);
        Client(std::string name, int age, std::string adress, std::string cpf);
        ~Client();

        int setName(std::string name);
        std::string getName() const;

        int setAge(int age);
        int getAge() const;

        int setAdress(std::string adress);
        std::string getAdress() const;

        int setCPF(std::string cpf);
        std::string getCPF() const;

        friend bool operator==(const Client &lhs, const Client &rhs);
        friend std::ostream &operator<<(std::ostream &os, const Client &client);
};

#endif