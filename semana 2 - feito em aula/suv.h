#ifndef SUV_H
#define SUV_H

#include "car.h"

class Suv : public Car {

    public:
		Suv();
		~Suv();  
		void setAno(int ano);
		int getAno();
    private: 
		int totalKm;

};

#endif

