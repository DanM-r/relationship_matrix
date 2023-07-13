#include "User.h"

int User::next_available_id = 0;

User::User( string username, string password ) {

    this->username = username;
    this->password = password;
    this->user_id = User::next_available_id;
    User::next_available_id++;
}

User::User( string username ) {

    this->username = username;
    this->password = "";
    this->user_id = -1;
}

string User::get_username() {

    return this->username;
}

int User::get_user_id() {

    return this->user_id;
}

void User::set_password( string password, string new_password) {

    if ( this->password == password ) {

        this->password = new_password;

    }
}

void User::set_username( string username) {

    this->username = username;
}

bool User::verify_password_input( string password) {

    return ( password == this->password );
}

bool User::operator==( User *user ) {

    if ( this->username == user->username
         && this->password == user->password ) {

        return true;

    }
}