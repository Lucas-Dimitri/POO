#include <iostream>
#include <list> 

#include "car.h"
#include "suv.h"

using namespace std;

int main(){

	Car meuCarro;  
	Suv meuSuv;
	list<Car*> *minhaLista = new list<Car*>; 
        //list<Car> *minhaListaDina = new list<Car>; 

	//minhaLista.push_front(meuCarro);
	for(int i  = 0; i < 1000; i++){
		minhaLista->push_front(new Suv); 
	}

	list<Car*>::iterator it; 
        for(it = minhaLista->begin(); it != minhaLista->end(); it++){
	    cout << (*it)->getId() << endl; 
	}

        for(Car* meuCarro : *minhaLista){
	    //cout << meuCarro->getId();
	    cout << "oi" << endl;
	}	    
        	
        Suv *meuSuvDinamico = new Suv; 

	meuSuv.setAno(2022);

        delete meuSuvDinamico; 
	
	return 1;
}

