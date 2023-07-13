#include "City.h"

City::City( string name, double distance_in_km ) {

    this->name = name;
    this->distance_in_km = distance_in_km;
}

City::City( string name ) {

    this->name = name;
    this->distance_in_km = 0;
}

string City::get_name() {

    return this->name;
}

double City::get_distance_in_km() {

    return this->distance_in_km;
}

void City::set_distance_in_km( double distance_in_km ) {

    this->distance_in_km = distance_in_km;
}

bool City::operator== ( City *city ) {

    return ( this->name == city->name );
}