#include "Employee.h"

Employee::Employee( string name, string position ) {

    this->name = name;
    this->position = position;
}

string Employee::get_name() {

    return this->name;
}

Employee::Employee( string name ) {

    this->name = name;
}

string Employee::get_position() {

    return this->position;
}

void Employee::set_name( string name ) {

    this->name = name;
}

void Employee::set_position( string position ) {

    this->position = position;
}

bool Employee::operator== ( Employee* employee ) {

    return this->name == employee->name;
}