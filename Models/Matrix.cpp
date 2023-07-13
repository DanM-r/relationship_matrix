#include "Matrix.h"

/*
    --------------------------------------------------------
    RELATION CLASS
*/

template <typename T>
Matrix<T>::Row::Relation::Relation() {

    this->next_relation = nullptr;
    this->relation_strength = 0;
}

template <typename T>
typename Matrix<T>::Row::Relation* Matrix<T>::Row::Relation::get_next_relation() {

    return this->next_relation;
}

template <typename T>
int Matrix<T>::Row::Relation::get_relation_strength() {

    return this->relation_strength;
}

template <typename T>
void Matrix<T>::Row::Relation::set_next_relation( Relation* next ) {

    this->next_relation = next;
}

template <typename T>
void Matrix<T>::Row::Relation::set_relation_strength( int relation_strength ) {

    this->relation_strength = relation_strength;
}

/*
    --------------------------------------------------------
    ROW CLASS
*/

template <typename T>
Matrix<T>::Row::Row( T* elem ) {

    this->elem = elem;
    this->next_row = nullptr;
    this->first_relation = nullptr;
}

template <typename T>
Matrix<T>::Row::~Row() {

    delete this->elem;
    Relation* rel_ptr = nullptr;

    do {

        rel_ptr = this->first_relation;
        this->first_relation = rel_ptr->get_next_relation();
        delete rel_ptr;

    } while ( this->first_relation );
}

template <typename T>
typename Matrix<T>::Row::Relation* Matrix<T>::Row::find_rel( int elem_i ) {

    if ( this->first_relation ) {

        Relation* rel_ptr = this->first_relation;
        int r_index = 0;

        while ( rel_ptr
                && r_index < elem_i ) {

            rel_ptr = rel_ptr->get_next_relation();
            r_index++;

        }
        return rel_ptr;

    }
    return nullptr;
}

template <typename T>
typename Matrix<T>::Row* Matrix<T>::Row::get_next_row() {

    return this->next_row;
}

template <typename T>
T* Matrix<T>::Row::get_elem() {

    return this->elem;
}

template <typename T>
int Matrix<T>::Row::get_relation( int elem_i ) {

    Relation* rel_ptr = this->find_rel( elem_i );

    if ( rel_ptr ) {

        return rel_ptr->get_relation_strength();

    }
    return -1;
}

template <typename T>
void Matrix<T>::Row::set_next_row( Row* next ) {

    this->next_row = next;
}

template <typename T>
void Matrix<T>::Row::set_elem( T* elem ) {

    this->elem = elem;
}

template <typename T>
bool Matrix<T>::Row::set_relation( int i_elem, int strength ) {

    Relation* r_ptr = this->find_rel( i_elem );

    if ( r_ptr ) {

        r_ptr->set_relation_strength( strength );
        return true;

    }
    return false;
}

template <typename T>
void Matrix<T>::Row::uniformize( int size ) {

    if ( !this->first_relation ) {

        this->first_relation = new Relation();

    }
    Relation* rel_ptr = this->first_relation;

    for ( int i = 1; i < size; i++ ) {

        if ( !rel_ptr->get_next_relation() ) {

            rel_ptr->set_next_relation( new Relation() );

        }
        rel_ptr = rel_ptr->get_next_relation();

    }
}

template <typename T>
typename Matrix<T>::Row::Relation* Matrix<T>::Row::find_relation( int i_elem ) {

    if ( this->first_relation ) {

        Relation* rel_ptr = this->first_relation;
        int i = 0;

        while ( rel_ptr
                && i < i_elem ) {

            rel_ptr = rel_ptr->get_next_relation();
            i++;

        }
        return rel_ptr;

    }
    return nullptr;
}

template <typename T>
void Matrix<T>::Row::remove_relations( int i_elem ) {

    Relation* rel_ptr = this->first_relation;

    if ( i_elem == 0 ) {

        this->first_relation = rel_ptr->get_next_relation();
        delete rel_ptr;
        return;

    }
    rel_ptr = this->find_rel( i_elem );
    Relation* before_rel_ptr = this->find_rel( i_elem - 1 );

    if ( rel_ptr && before_rel_ptr ) {

        before_rel_ptr->set_next_relation( rel_ptr->get_next_relation() );
        delete rel_ptr;
        return;

    }
    return;
}

template <typename T>
void Matrix<T>::Row::print_row( ostream& out ) {

    Relation* rel_ptr = this->first_relation;

    out << setw( 25 ) << this->elem << setw( 3 ) << " : ";

    while ( rel_ptr ) {

        out << setw( 3 ) << rel_ptr->get_relation_strength();
        rel_ptr = rel_ptr->get_next_relation();

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

    Row* row_ptr;

    do {

        row_ptr = this->first_row;
        this->first_row->set_next_row( row_ptr->get_next_row() );
        delete row_ptr;

    } while ( this->first_row );
}

template <typename T>
void Matrix<T>::fill_rows() {

    Row* r_ptr = this->first_row;

    while ( r_ptr ) {

        r_ptr->uniformize( this->size );
        r_ptr = r_ptr->get_next_row();

    }
}

template <typename T>
void Matrix<T>::empty_rows( int i_elem ) {

    Row* row_ptr = this->first_row;

    while ( row_ptr ) {

        row_ptr->remove_relations( i_elem );
        row_ptr = row_ptr->get_next_row();
    }
}

template <typename T>
int Matrix<T>::get_id( T elem ) {

    if ( this->first_row ) {

        Row* row_ptr = this->first_row;
        int i = 0;

        while ( row_ptr ) {

            if ( elem == row_ptr->get_elem() ) {

                return i;

            }
            row_ptr = row_ptr->get_next_row();
            i++;
        }
    }
    return -1;
}

template <typename T>
void Matrix<T>::add( T* elem ) {

    if ( this->first_row ) {

        this->last_row->set_next_row( new Row( elem ) );
        this->last_row = this->last_row->get_next_row();

    } else {

        this->first_row = new Row( elem );
        this->last_row = this->first_row;

    }
    this->size++;
    this->fill_rows();
}

template <typename T>
typename Matrix<T>::Row* Matrix<T>::find_row( int i_elem ) {

    if ( this->first_row ) {

        Row* row_ptr = this->first_row;
        int i = 0;

        while ( row_ptr
                && i < i_elem ) {

            row_ptr = row_ptr->get_next_row();
            i++;

        }
        return row_ptr;
    }
    return nullptr;
}

template <typename T>
bool Matrix<T>::remove( int i_elem ) {

    Row* r_ptr = nullptr;

    if ( i_elem == 0 ) {

        r_ptr = this->first_row;
        this->first_row = this->first_row->get_next_row();
        delete r_ptr;
        this->size--;
        this->empty_rows( i_elem );
        return true;

    } else if ( i_elem < this->size ) {

        Row* row_before = this->find_row( i_elem - 1 );
        r_ptr = row_before->get_next_row();
        row_before->set_next_row( r_ptr->get_next_row() );
        delete r_ptr;
        this->size--;
        this->empty_rows( i_elem );
        return true;

    }
    return false;
}

template <typename T>
bool Matrix<T>::modify( int i_first_elem, int i_second_elem, int strength ) {

    Row* row1_ptr = this->find_row( i_first_elem );
    Row* row2_ptr = this->find_row( i_second_elem );

    if ( row1_ptr
         && row2_ptr ) {

        row1_ptr->set_relation( i_second_elem, strength );

        if ( this->is_symmetrical ) {

            row2_ptr->set_relation( i_first_elem, strength );
            return true;

        }
        return true;

    }
    return false;
}

template <typename T>
void Matrix<T>::print_matrix( ostream& out ) const {

    Row* r_ptr = this->first_row;

    while ( r_ptr ) {

        r_ptr->print_row( out );
        r_ptr = r_ptr->get_next_row();

    }
}

template <typename T>
void Matrix<T>::operator+= ( T* elem ) {

    this->add( elem );

}

template <typename T>
ostream& operator<<( ostream& out, const Matrix<T>* matrix ) {
    //Asumes that the element has a << operator
    matrix->print_matrix( out );
    return out;

}