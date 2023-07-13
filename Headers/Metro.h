#ifndef RELATIONSHIP_MATRIX_METRO_H
#define RELATIONSHIP_MATRIX_METRO_H

// Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

// Files
#include "Matrix.h"
#include "Matrix.cpp"
#include "City.h"

// Using
using std::cout;
using std::endl;
using std::flush;
using std::cin;
using std::setfill;
using std::setw;
using std::left;
using std::string;
using std::getline;
using std::system;

class Metro {

    Matrix<City>* tickets;

public:
    Metro();
    ~Metro();

    void menu();
    void see_ticket_prices();
    void add_route();
    void remove_route();
    bool verify_city_exists( string city_name );
    void modify_ticket_price();

};

#endif
