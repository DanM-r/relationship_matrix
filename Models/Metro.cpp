#include "Metro.h"

Metro::Metro() {

    this->tickets = new Matrix<City>( false );
}

Metro::~Metro() {

    delete this->tickets;
}

void Metro::menu() {

    int user_option = 0;

    try {

        cout << setfill( '-' );
        cout << setw( 1 ) << "+" << setw( 22 ) << "-" << setw( 1 ) << "+" << endl;
        cout << setfill( ' ' );
        cout << setw( 2 ) << "| " << setw( 20 ) << "MENU - Metro System" << setw( 2 ) << " |" << endl;
        cout << setw( 2 ) << "| " << setw( 20 ) << "1. Check price difference" << setw( 2 ) << " |" << endl;
        cout << setw( 2 ) << "| " << setw( 20 ) << "2. Create a new route" << setw( 2 ) << " |" << endl;
        cout << setw( 2 ) << "| " << setw( 20 ) << "3. Remove a route" << setw( 2 ) << " |" << endl;
        cout << setw( 2 ) << "| " << setw( 20 ) << "4. Modify price difference" << setw( 2 ) << " |" << endl;
        cout << setw( 2 ) << "| " << setw( 20 ) << "5. Exit" << setw( 2 ) << " |" << endl;
        cout << setfill( '-' );
        cout << setw( 1 ) << "+" << setw( 22 ) << "-" << setw( 1 ) << "+" << endl;
        cout << setfill( ' ' );
        cin >> user_option;
        cin.exceptions( std::istream::failbit );

        do {

            switch ( user_option ) {

                case 1:
                    system( "clear" );
                    this->see_ticket_prices();
                    break;

                case 2:
                    system( "clear" );
                    this->add_route();
                    break;

                case 3:
                    system( "clear" );
                    this->remove_route();
                    break;

                case 4:
                    system( "clear" );
                    this->modify_ticket_price();
                    break;

                case 5:
                    system( "clear" );
                    break;

                default:
                    cout << "< ! > Error. That option is not allowed." << endl;
            }
        } while ( user_option == 5 );

    } catch ( const std::ios_base::failure& fail ) {

        system( "clear" );
        cout << "< ! > Error. Invalid input. ";
        cout << fail.what() << endl;
        cin.clear();
        cin.ignore( 1000, '\n' );
    }
}

bool Metro::verify_city_exists( string city_name ) {

    if ( this->tickets->get_id( City( city_name ) ) == -1 ) {

        return false;

    }
    return true;
}

void Metro::see_ticket_prices() {

    cout << "- - - Fee increase across all cities - - -" << endl;
    cout << this->tickets << endl;
    cout << "> The price is calculated multiplying the distance in km by the fee margin divided by 10" << endl;
}

void Metro::add_route() {

    string city_name;
    double distance_in_km = 0;

    try {

        cout << "> Enter the name of the city: " << flush;
        getline( cin, city_name );
        cout << "> Enter the distance in km from the station to the city: " << flush;
        cin >> distance_in_km;
        cin.exceptions();
        this->tickets->add( new City( city_name, distance_in_km ) );

    } catch ( std::ios_base::failure& fail ) {

        system( "clear" );
        cout << "< ! > Error. Invalid input. ";
        cout << fail.what() << endl;
        cin.clear();
        cin.ignore( 1000, '\n' );
    }

}

void Metro::remove_route() {

    string city_name;

    cout << "> Enter the name of the city: " << flush;
    getline( cin, city_name );

    if ( this->verify_city_exists( city_name ) ) {

        int city_id = this->tickets->get_id( City( city_name ) );
        this->tickets->remove( city_id );

    } else {

        cout << "< ! > Error. That city doesn't exists." << endl;

    }
}

void Metro::modify_ticket_price() {

    string origin_city, destination_city;
    this->see_ticket_prices();
    cout << "> Enter the name of the origin city: " << flush;
    getline( cin, origin_city );
    cout << endl <<  "> Enter the name of the destination city: " << flush;
    getline( cin, destination_city );

    try {

        if ( this->verify_city_exists( origin_city )
             && this->verify_city_exists( destination_city ) ) {

            int origin_city_index = this->tickets->get_id( City( origin_city ) );
            int dest_city_index = this->tickets->get_id( City( destination_city ) );
            int price_difference = 0;
            cout << "> Enter the new ticket fee: " << flush;
            cin >> price_difference;
            cin.exceptions( std::istream::failbit );
            this->tickets->modify( origin_city_index, dest_city_index, price_difference );

        } else {

            cout << "< ! > Error. The city doesn't exists." << endl;
        }
    } catch ( std::ios_base::failure& fail ) {

        system( "clear" );
        cout << "< ! > Error. Invalid input. ";
        cout << fail.what() << endl;
        cin.clear();
        cin.ignore( 1000, '\n' );
    }
}