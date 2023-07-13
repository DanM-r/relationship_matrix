#include "Company.h"

Company::Company() {

    this->employees = new Matrix<Employee>( true );
}

Company::~Company() {

    delete this->employees;
}

void Company::menu() {

    int user_option = 0;

    try {

        cout << setfill( '-' );
        cout << setw( 1 ) << "+" << setw( 22 ) << "-" << setw( 1 ) << "+" << endl;
        cout << setfill( ' ' );
        cout << setw( 2 ) << "| " << setw( 20 ) << "MENU - Company" << setw( 2 ) << " |" << endl;
        cout << setw( 2 ) << "| " << setw( 20 ) << "1. Check relationships>" << setw( 2 ) << " |" << endl;
        cout << setw( 2 ) << "| " << setw( 20 ) << "2. Add employee" << setw( 2 ) << " |" << endl;
        cout << setw( 2 ) << "| " << setw( 20 ) << "3. Remove employee" << setw( 2 ) << " |" << endl;
        cout << setw( 2 ) << "| " << setw( 20 ) << "4. Modify relationship" << setw( 2 ) << " |" << endl;
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
                    this->check_relations();
                    break;

                case 2:
                    system( "clear" );
                    this->add_employee();
                    break;

                case 3:
                    system( "clear" );
                    this->remove_employee();
                    break;

                case 4:
                    system( "clear" );
                    this->modify_relation();
                    break;

                case 5:
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

void Company::check_relations() {

    cout << "- - - Relationships between employees - - -" << endl;
    cout << this->employees << endl;
    cout << "- - - 0 = no relation | 1 = related - - -" << endl;
}

void Company::add_employee() {

    string name, position;
    cout << "Enter the name of the employee: " << flush;
    getline( cin, name );
    cout << "Enter the position of the employee: " << flush;
    getline( cin, position );
    this->employees->add( new Employee( name, position ) );
}

void Company::remove_employee() {

    string name;
    cout << "Enter the name of the employee to remove: " << flush;
    getline( cin, name );

    if ( this->verify_employee_exists( name ) ) {

        int employee_id = this->employees->get_id( Employee( name ) );
        this->employees->remove( employee_id );
        return;

    }
    cout << "< ! > Error. That employee doesn't exists." << endl;
}

bool Company::verify_employee_exists( string username ) {

    if ( this->employees->get_id( Employee( username ) ) == -1 ) {

        return false;

    }
    return true;
}

void Company::modify_relation() {

    string name_employee_1, name_employee_2, new_relation;
    this->check_relations();
    cout << "> Enter the name of the first employee: " << flush;
    getline(cin, name_employee_1);
    cout << "> Enter the name of the second employee: " << flush;
    getline(cin, name_employee_2);

    if (this->verify_employee_exists(name_employee_1)
        && this->verify_employee_exists(name_employee_2)) {

        int employee1_id = this->employees->get_id(Employee(name_employee_1));
        int employee2_id = this->employees->get_id(Employee(name_employee_2));
        cout << "> Are these two employees working together? y/n: " << flush;
        cin >> new_relation;

        if (new_relation.size() == 1
            && new_relation == "y" || new_relation == "n") {

            if (new_relation == "y") {

                this->employees->modify(employee1_id, employee2_id, 1);
                return;

            } else {

                this->employees->modify(employee1_id, employee2_id, 0);
                return;

            }
        }
        cout << "< ! > Error. Invalid input." << endl;
        return;

    }
    cout << "< ! > Error. Those employees don't exist." << endl;

}