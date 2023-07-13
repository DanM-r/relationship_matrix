#ifndef RELATIONSHIP_MATRIX_CITY_H
#define RELATIONSHIP_MATRIX_CITY_H

// Libraries
#include <string>

// Files

// Using
using std::string;

class City {

    string name;
    double distance_in_km;

public:

    City( string name, double distance_in_km );
    City( string name );
    ~City() = default;

    string get_name();
    double get_distance_in_km();

    void set_distance_in_km( double distance_in_km );

    bool operator== ( City* city );
};

#endif