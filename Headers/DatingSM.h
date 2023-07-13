#ifndef RELATIONSHIP_MATRIX_DATINGSM_H
#define RELATIONSHIP_MATRIX_DATINGSM_H

// Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

// Files
#include "Matrix.h"
#include "Matrix.cpp"
#include "User.h"

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

class DatingSM {

    Matrix<User>* user_relations;

public:
    DatingSM();
    ~DatingSM();

    void login();
    bool verify_user_exist( string username );
    void menu( User* user );
    void discover_users( User* user );

};

#endif
