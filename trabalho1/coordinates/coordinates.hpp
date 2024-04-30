#ifndef COORDINATES_H
#define COORDINATES_H

#include "../GeoShell/GeoShell.hpp"
/*
[GeoShell](https://github.com/diogo2m/geoshell) 
© 2024 by [Diogo Mainart Monteiro](https://github.com/diogo2m) is licensed under [CC BY 4.0](https://creativecommons.org/licenses/by/4.0/?ref=chooser-v1).
*/

#include<iostream>
#include <cmath>

class Coordinates{
private:
    static constexpr double PI = 3.14159;
    static constexpr int R = 6371;
    double lat;
    double lng;

    static double toRadians(double d);
public:
    Coordinates( double lat = 0, double lng = 0);
    Coordinates( std::string address);
    ~Coordinates();

    void set_coordinates( double lat, double lng);
    double* get_coordinates();

    static double calculate_distance( Coordinates c1, Coordinates c2);

    bool operator==( const Coordinates& other);
    
    friend std::ostream& operator<<( std::ostream& os, const Coordinates & obj);
};


#endif