#ifndef RELATIONSHIP_MATRIX_USER_H
#define RELATIONSHIP_MATRIX_USER_H

// Libraries
#include <string>

// Files

// Using
using std::string;

class User {

    static int next_available_id;

    int user_id;
    string username;
    string password;

public:
    User( string username, string password );
    User( string username );
    ~User() = default;

    string get_username();
    int get_user_id();

    void set_username( string username );
    void set_password( string password, string new_password );
    bool verify_password_input( string password );

    bool operator== ( User* user );

};

#endif