#ifndef CAR_H 
#define CAR_H

class Car{

	private: 
	    int id; 
    public:
        Car();
        ~Car(); 
	    void setId(int id);
	    int getId();
	protected:
	    int ano; 

};

#endif
