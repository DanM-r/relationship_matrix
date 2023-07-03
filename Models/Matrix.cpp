#include "../Headers/Matrix.h"

/*
    Relationship Constructors & Destructors
*/

template <typename Element>
Matrix<Element>::Row::Relationship::Relationship() {

    this->next = nullptr;
    this->value = 0;
}

template <typename Element>
Matrix<Element>::Row::Relationship::~Relationship() { }

template <typename Element>
Matrix<Element>::Row::Relationship* Matrix<Element>::Row::Relationship::get_next() {

    return this->next;
}

template <typename Element>
void Matrix<Element>::Row::Relationship::set_next( Relationship* next ) {

    this->next = next;
}

/*
    Row Constructors & Destructors
*/

template <typename Element>
Matrix<Element>::Row::Row( Element* element, int size ) {

    this->first_collumn = nullptr;
    this->element = element;
    this->size = size;
    this->init_relationships();

}

template <typename Element>
Matrix<Element>::Row::~Row() {

    delete this->element;
    for ( int relationship_index = this->size; relationship_index >= 0; relationship_index-- ) {

        this->remove( relationship_index );

    }
}

/*
    Row Management Methods
*/

template <typename Element>
void Matrix<Element>::Row::init_relationships() {

    Relationship* relation_ptr = this->first_collumn;

    while ( relation_ptr ) {

        relation_ptr = new Relationship();
        relation_ptr = relation_ptr->get_next();

    }
}

template <typename Element>
void Matrix<Element>::Row::set_next( Row* next ) {

    this->next = next;
}

template <typename Element>
Matrix<Element>::Row* Matrix<Element>::Row::get_next() {

    return this->next;
}

template <typename Element>
bool Matrix<Element>::Row::remove( int collumn ) {

    if ( this->first_collumn ) {

        Relationship* relation_ptr;

        if ( collumn == 0 ) {

            relation_ptr = this->first_collumn;
            this->first_collumn = this->first_collumn->get_next();

        } else {

            Relationship* before_relation_ptr = this->first_collumn;
            int i = 0;3
            while ( before_relation_ptr
            && ( i + 1 ) < collumn ) {

                before_relation_ptr = before_relation_ptr->get_next();
                i++;

            }

            if ( ( i + 1 ) == collumn ) {

                relation_ptr = before_relation_ptr->get_next();
                before_relation_ptr->set_next( relation_ptr->get_next() );

            } else {

                return false;

            }
        }
        relation_ptr->set_next( nullptr );

        delete relation_ptr;
        return true;

    }
    return false;
}

/*
    Matrix Constructors & Destructors
*/

template <typename Element>
Matrix<Element>::Matrix( int size, bool is_symmetrical ) {

    this->first_row = nullptr;
    this->size = size;
    this->is_symmetrical = is_symmetrical;
}

template <typename Element>
Matrix<Element>::~Matrix() {

    for ( int row = this->size; row >= 0; row-- ) {

        this->remove( row );

    }
}

/*
    Matrix Row Management
*/

template <typename Element>
void Matrix<Element>::add( Element* element ) {
    
    this->size++;
    if ( this->first_row ) {

        this->bottom_row->set_next( new Row( element, this->size ) );
        this->bottom_row = this->bottom_row->get_next();

    } else {

        this->first_row = new Row( element, this->size );
        this->first_row = this->bottom_row;

    }
}

template <typename Element>
Matrix<Element>::Row* Matrix<Element>::find_row( int row_index ) {

    if ( this->first_row ) {

        if ( row_index == 0 ) {

            return this->first_row;

        } else {

            Row* row_iterator = this->first_row;
            int index_row_iterator = 0;

            while ( row_iterator 
            && index_row_iterator == row_index ) {
                
                row_iterator = row_iterator->get_next();
                index_row_iterator++;

            }

            if ( row_iterator ) {

                return row_iterator;

            }
            return nullptr;   
        }
    }
    return nullptr;
}

template <typename Element>
Element* Matrix<Element>::find_element( int row_index ) {

    if ( this->first_row ) {

        if ( row_index == 0 ) {

            return this->first_row->ge;

        } else {

            Row* row_iterator = this->first_row;
            int index_row_iterator = 0;

            while ( row_iterator 
            && index_row_iterator == row_index ) {
                
                row_iterator = row_iterator->get_next();
                index_row_iterator++;

            }

            if ( row_iterator ) {

                return row_iterator;

            }
            return nullptr;
            
        }
    }
    return nullptr;
}

template <typename Element>
Element* Matrix<Element>::remove( int row_index ) {

    Row* row_iterator;

    if ( row_index == 0 ) {

        row_iterator = this->first_row;
        this->first_row  = this->first_row->get_next();
        row_ptr->set_next( nullptr );

    } else {

        row_iterator = this->find_element( row_index );

        if ( row_iterator ) {

            Row* previous_row_iterator = this->find_element( row_index - 1 );
            previous_row_iterator->set_next( row_iterator->get_next() );
            row_iterator->set_next( nullptr );

        }
    }
    return row_iterator;

}

template <typename Element>
bool Matrix<Element>::modify( int row, int collumn, int modified_relationship ) {

    

}
