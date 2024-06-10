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
        std::string phoneNumber;
        std::string email;
        std::string adress;
        std::string cpf;

    public:

        Client();
        Client(std::string name, std::string adress, std::string cpf);
        Client(std::string name, int age, std::string adress, std::string cpf);
        Client(std::string name, int age, std::string adress, std::string cpf, std::string email, std::string phoneNumber);
        ~Client();

        int setName(std::string name);
        std::string getName() const;

        int setAge(int age);
        int getAge() const;

        int setAdress(std::string adress);
        std::string getAdress() const;

        int setCPF(std::string cpf);
        std::string getCPF() const;

        int setEmail( std::string email);
        std::string getEmail() const;

        int setPhoneNumber( std::string phoneNumber);
        std::string getPhoneNumber() const;

        friend bool operator==(const Client &lhs, const Client &rhs);
        friend std::ostream &operator<<(std::ostream &os, const Client &client);
};

#endif