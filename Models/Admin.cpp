#include "Admin.h"

void Admin::menu() {

    int user_option = 0;

    try {

        cout << setfill( '-' );
        cout << setw( 1 ) << "+" << setw( 22 ) << "-" << setw( 1 ) << "+" << endl;
        cout << setfill( ' ' );
        cout << setw( 2 ) << "| " << setw( 20 ) << "MENU - Choose a program to run" << setw( 2 ) << " |" << endl;
        cout << setw( 2 ) << "| " << setw( 20 ) << "1. Dating SM" << setw( 2 ) << " |" << endl;
        cout << setw( 2 ) << "| " << setw( 20 ) << "2. Metro System" << setw( 2 ) << " |" << endl;
        cout << setw( 2 ) << "| " << setw( 20 ) << "3. Company Relationships" << setw( 2 ) << " |" << endl;
        cout << setw( 2 ) << "| " << setw( 20 ) << "4. Exit" << setw( 2 ) << " |" << endl;
        cout << setfill( '-' );
        cout << setw( 1 ) << "+" << setw( 22 ) << "-" << setw( 1 ) << "+" << endl;
        cout << setfill( ' ' );
        cin >> user_option;
        cin.exceptions( std::istream::failbit );

        do {

            switch ( user_option ) {
                case 1:
                    system( "clear" );
                    this->dsm = new DatingSM();
                    this->dsm->login();
                    delete this->dsm;
                    break;

                case 2:
                    system( "clear" );
                    this->m = new Metro();
                    this->m->menu();
                    delete this->m;
                    break;

                case 3:
                    system( "clear" );
                    this->c = new Company();
                    this->c->menu();
                    delete this->c;
                    break;

                case 4:
                    system( "clear" );
                    break;

                default:
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