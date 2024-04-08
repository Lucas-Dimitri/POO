#include "suv.h"
#include <iostream>

Suv::Suv(){

    std::cout << "Ola da class SUV" << std::endl;

}

Suv::~Suv(){
    std::cout << "Ola do destruturo da classe SUV" << std::endl;
}

void Suv::setAno(int ano){
	this->ano = ano;
}
	
int Suv::getAno(){
	return this->ano;
}
