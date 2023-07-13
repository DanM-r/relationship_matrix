#ifndef RELATIONSHIP_MATRIX_COMPANY_H
#define RELATIONSHIP_MATRIX_COMPANY_H

// Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

// Files
#include "Matrix.h"
#include "Matrix.cpp"
#include "Employee.h"

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

class Company {

    Matrix<Employee>* employees;

public:
    Company();
    ~Company();

    void menu();
    void add_employee();
    void remove_employee();
    bool verify_employee_exists( string username );
    void modify_relation();
    void check_relations();

};

#endif
