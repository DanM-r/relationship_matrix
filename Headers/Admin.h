#ifndef RELATIONSHIP_MATRIX_ADMIN_H
#define RELATIONSHIP_MATRIX_ADMIN_H

// Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

// Files
#include "DatingSM.h"
#include "Metro.h"
#include "Company.h"

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

class Admin {

    DatingSM* dsm;
    Metro* m;
    Company* c;

public:
    Admin() = default;
    ~Admin() = default;

    void menu();

};

#endif