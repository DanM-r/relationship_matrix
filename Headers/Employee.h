#ifndef RELATIONSHIP_MATRIX_EMPLOYEE_H
#define RELATIONSHIP_MATRIX_EMPLOYEE_H

// Libraries
#include <string>

// Files

// Using
using std::string;

class Employee {

    string name;
    string position;

public:
    Employee( string name, string position );
    Employee( string name );

    ~Employee() = default;

    string get_name();
    string get_position();

    void set_name( string name );
    void set_position( string position );

    bool operator== ( Employee* employee );

};
#endif
