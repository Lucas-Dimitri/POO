#include "car.h"
#include <iostream>


Car::Car(){

	std::cout << "Constructor da Classe Carro" << std::endl;

}

Car::~Car(){
}

void Car::setId(int id){
   this->id = id;
}

int Car::getId(){
   return this->id;
}
