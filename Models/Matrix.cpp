#include "../Headers/Matrix.h"

/*
    --------------------------------------------------------
    RELATION CLASS
*/

template <typename T>
Matrix<T>::Row::Relation::Relation() {

    this->next = nullptr;
    this->relation_strenght = 0;
}

template <typename T>
Matrix<T>::Row::Relation::~Relation() { }

template <typename T>
Matrix<T>::Row::Relation* Matrix<T>::Row::Relation::get_next() {

    return this->next;
}

template <typename T>
int Matrix<T>::Row::Relation::get_relation_strenght() {

    return this->relation_strenght;
}

template <typename T>
void Matrix<T>::Row::Relation::set_next( Relation* next ) {

    this->next = next;
}

template <typename T>
void Matrix<T>::Row::Relation::set_relation_strenght( int relation_strenght ) {

    this->relation_strenght = relation_strenght;
}

/*
    --------------------------------------------------------
    ROW CLASS
*/

template <typename T>
Matrix<T>::Row::Row( T* elem ) {

    this->elem = elem;
    this->next = nullptr;
    this->first_relation = nullptr;
}

template <typename T>
Matrix<T>::Row::~Row() {

    delete this->elem;
    Relation* r_ptr = this->first_relation;
    
    while ( this->first_relation ) {

        r_ptr = this->first_relation;

        while ( r_ptr->get_next()->get_next() ) {

            r_ptr = r_ptr->get_next();

        }
        delete r_ptr->get_next();
        r_ptr->set_next( nullptr );
    }
}

template <typename T>
Matrix<T>::Row* Matrix<T>::Row::get_next() {

    return this->next;
}

template <typename T>
T* Matrix<T>::Row::get_elem() {

    return this->elem;
}

template <typename T>
int Matrix<T>::Row::get_relation( int elem_i ) {

    Relation* rel_ptr = this->find_rel( elem_i );

    if ( rel_ptr ) {

        return rel_ptr->get_relation_strenght();

    }
    return -1;
}

template <typename T>
void Matrix<T>::Row::set_next( Row* next ) {

    this->next = next;
}

template <typename T>
void Matrix<T>::Row::set_elem( T* elem ) {

    this->elem = elem;
}

template <typename T>
bool Matrix<T>::Row::set_relation( int i_elem, int strength ) {

    Relation* r_ptr = this->find_rel( i_elem );

    if ( r_ptr ) {

        r_ptr->set_relation_strenght( strength );
        return true;

    }
    return false;
}

template <typename T>
void Matrix<T>::Row::uniformize( int size ) {

    Relation* rel_ptr = this->first_relation;

    for ( int rel_i = 0; rel_i < size; rel_i++ ) {

        if ( !rel_ptr ) {

            rel_ptr = new Relation();

        }
        rel_ptr = rel_ptr->get_next();
    }
}

template <typename T>
Matrix<T>::Row::Relation* Matrix<T>::Row::find_rel( int elem_i ) {

    Relation* rel_ptr = this->first_relation;
    int r_index = 0;

    while ( rel_ptr
    && r_index < elem_i ) {

        rel_ptr = rel_ptr->get_next();

    }

    if ( rel_ptr ) {

        return rel_ptr;

    }
    return nullptr;
}

template <typename T>
void Matrix<T>::Row::print_row( ostream& out ) {

    Relation* rel_ptr = this->first_relation;

    out << setw( 25 ) << this->elem << setw( 3 ) << " : ";

    while ( rel_ptr ) {

        out << setw( 3 ) << rel_ptr->get_relation_strenght();
        rel_ptr = rel_ptr->get_next();

    }
    out << endl;
}

/*
    --------------------------------------------------------
    MATRIX CLASS
*/

template <typename T>
Matrix<T>::Matrix( bool is_symmetrical ) {

    this->size = 0;
    this->is_symmetrical = is_symmetrical;
    this->first_row = nullptr;
    this->last_row = nullptr;
}

template <typename T>
Matrix<T>::~Matrix() { 

    Row* r_ptr = this->first_row;

    while ( this->first_row ) {

        while ( r_ptr->get_next()->get_next() ) {

            r_ptr = r_ptr->get_next();

        }
        delete r_ptr->get_next();
        r_ptr->set_next( nullptr );

    }
}

template <typename T>
void Matrix<T>::add( T* elem ) {

    if ( this->first_row ) {

        this->last_row->set_next( new Row( elem ) );
        this->last_row = this->last_row->get_next();

    } else {

        this->first_row = new Row( elem );
        this->last_row = this->first_row;

    }
    this->size++;
    this->fill_rows();
}

template <typename T>
void Matrix<T>::fill_rows() {

    Row* r_ptr = this->first_row;

    while ( r_ptr ) {

        r_ptr->uniformize( this->size );
        r_ptr = r_ptr->get_next();

    }
}

template <typename T>
Matrix<T>::Row* Matrix<T>::find_row( int i_elem ) {

    if ( this->first_row ) {

        Row* r_ptr = this->first_row;
        int i = 0;

        while ( r_ptr
        && i < i_elem ) {

            r_ptr = r_ptr->get_next();

        }
        return r_ptr;
    }
    return nullptr;
}

template <typename T>
bool Matrix<T>::remove( int i_elem ) {

    Row* r_ptr = nullptr;

    if ( i_elem == 0 ) {
        
        r_ptr = this->first_row;
        this->first_row = this->first_row->get_next();
        delete r_ptr;
        this->size--;
        return true;
        
    } else if ( i_elem < this->size ) {

        Row* row_before = this->find_row( i_elem - 1 );
        r_ptr = row_before->get_next();
        row_before->set_next( r_ptr->get_next() );
        delete r_ptr;
        this->size--;
        return true;

    }
    return false;
}

template <typename T>
bool Matrix<T>::modify( int i_first_elem, int i_second_elem, int strength ) {

    Row* r_ptr = this->find_row( i_first_elem );

    if ( r_ptr ) {

        return r_ptr->set_relation( i_second_elem, strength );

    }
    return false;
}

template <typename T>
void Matrix<T>::print_matrix( ostream& out ) {

    Row* r_ptr = this->first_row;

    while ( r_ptr ) {

        r_ptr->print_row( out );
        r_ptr = r_ptr->get_next();

    }
}

template <typename T>
void Matrix<T>::operator+= ( T* elem ) {

    this->add( elem );

}

template <typename T>
ostream& operator<<( ostream& out, const Matrix<T>* matrix ) {
    /*
        Asumes that the element has a << operator
    */
    matrix->print_matrix( out );
    return out;

}