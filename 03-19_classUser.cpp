#include <iostream>

using namespace std;

class User{
    // atributos da classe
    public:
        string adress;
    private:
        int idade;
        string nome;
    
    // metodos de classe
    public:
        void setIdade(int minhaIdade){
            this->idade = idade;
            // idade = minhaIdade;
        }
        int getIdade(){
            return this->idade;
        }

        void setNome(string nome){
            this->nome = nome;
            // idade = minhaIdade;
        }
        string getNome(){
            return this->nome;
        }
};

int main(){
    User meuUsuario;
    meuUsuario.setIdade(23);
    meuUsuario.setNome("lucas");
    cout << "User 1" << meuUsuario.getIdade();

    User meuUsuario2;
    meuUsuario2.setIdade(20);

    // user *meuUsuario3 = new User;
    // meuUsuario3->setIdade(30);
    // meuUsuario3 ->setNome("Gaspatcho");
    // delete meuUsuario3;

    return 0;
}