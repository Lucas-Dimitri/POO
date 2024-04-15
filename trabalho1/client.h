#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <ostream>
#include <iostream>

class Client
{
    private:
        std::string nome;
        int idade;
        std::string endereco;
        std::string cpf;

    public:

        Client();
        Client(std::string nome, int idade, std::string endereco, std::string cpf);
        ~Client();

        int setNome(std::string nome);
        std::string getNome() const;

        int setIdade(int idade);
        int getIdade() const;

        int setEndereco(std::string endereco);
        std::string getEndereco() const;

        int setCPF(std::string cpf);
        std::string getCPF() const;

        friend bool operator==(const Client &lhs, const Client &rhs);
        friend std::ostream &operator<<(std::ostream &os, const Client &client);
};

#endif