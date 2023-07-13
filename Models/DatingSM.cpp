#include "DatingSM.h"

DatingSM::DatingSM() {

    // Insert users in here
    this->user_relations = new Matrix<User>( false );
    *this->user_relations += new User( "daniel", "holi123" );
    *this->user_relations += new User( "john", "123456seven" );
    *this->user_relations += new User( "krista", "Dylan_2791" );
    *this->user_relations += new User( "juan", "v4l@" );
    *this->user_relations += new User( "maverick", "mave4545" );
}

DatingSM::~DatingSM() {

    delete this->user_relations;
}

void DatingSM::login() {

    string username, password;

    cout << left;
    cout << "- - - Dating Social Media App - - -" << endl;
    cout << "> Username: " << flush;
    getline( cin, username );

    if ( this->verify_user_exist( username ) ) {

        User* loged_in_user; //= this->user_relations->find_elem( User( username ) );
        cout << "> Password: " << flush;
        getline( cin, password );

        if ( loged_in_user->verify_password_input( password ) ) {

            system( "clear" );
            this->menu(loged_in_user);

        }
    } else {

        system( "clear" );
        cout << "< ! > Error. The username entered doesn't exist." << endl;

    }
}

bool DatingSM::verify_user_exist( string username ) {

    /*
        if ( this->user_relations->get_id( User( username ) ) == -1 ) {

            return false;

        }
        return true;
    */
    return false;
}

void DatingSM::menu( User* user ) {

    int user_option = 0;

    try {

        cout << setfill( '-' );
        cout << setw( 1 ) << "+" << setw( 22 ) << "-" << setw( 1 ) << "+" << endl;
        cout << setfill( ' ' );
        cout << setw( 2 ) << "| " << setw( 20 ) << "MENU" << setw( 2 ) << " |" << endl;
        cout << setw( 2 ) << "| " << setw( 20 ) << "1. Discover users" << setw( 2 ) << " |" << endl;
        cout << setw( 2 ) << "| " << setw( 20 ) << "2. Exit" << setw( 2 ) << " |" << endl;
        cout << setfill( '-' );
        cout << setw( 1 ) << "+" << setw( 22 ) << "-" << setw( 1 ) << "+" << endl;
        cout << setfill( ' ' );
        cin >> user_option;
        cin.exceptions( std::istream::failbit );

        do {

            if ( user_option == 1 ) {

                system( "clear ");
                this->discover_users( user );

            } else if ( user_option == 2 ) {

                system( "clear" );

            } else {

                cout << "< ! > Error. That option is not allowed." << endl;

            }
        } while ( user_option == 2 );

    } catch ( const std::ios_base::failure& fail ) {

        system( "clear" );
        cout << "< ! > Error. Invalid input. ";
        cout << fail.what() << endl;
        cin.clear();
        cin.ignore( 1000, '\n' );

    }
}

void DatingSM::discover_users( User *user ) {
    // asuming the user idex is the same to the matrix index
    string action_to_user;

    try {

        cout << "- - - l = like | f = follow - - -" << endl;
        // cout << this->user_relations << endl;
        cout << "> Enter the username and next to it the action you want to do. ( e.g. frank f )" << endl;
        getline( cin, action_to_user );
        string username = action_to_user.substr( 0, action_to_user.find( ' ' ) );
        string action = action_to_user.substr( action_to_user.find( ' ' ), 1 );

        if ( this->verify_user_exist( username )
             && action.size() == 1
             && action == "l" || action == "f" ) {

            // int contact_id = this->user_relations->get_index( User( username ) );
            // int current_relation = this->user_relations[ user->get_user_id() ][ contact_id ];

            if ( action == "l" ) {

                // this->user_relations->modify( user->get_user_id(), contact_id, current_relation + 1 );

            }
            // this->user_relations->modify( user->get_user_id(), contact_id, current_relation + 2 );

        } else {

            throw 0;

        }
    } catch ( int error_code ) {

        if ( error_code == 0 ) {

            cout << "< ! > Error. That user doesn´t exist" << endl;

        }

    }
}