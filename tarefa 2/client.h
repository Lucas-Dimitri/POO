#ifndef CLIENT_H
#define CLIENT_H
#include <string>

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
        std::string getNome();

        int setIdade(int idade);
        int getIdade();

        int setEndereco(std::string endereco);
        std::string getEndereco();

        int setCPF(std::string cpf);
        std::string getCPF();

};

#endif