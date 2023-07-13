#ifndef RELATIONSHIP_MATRIX_MATRIX_H
#define RELATIONSHIP_MATRIX_MATRIX_H

    // Libraries
    #include <iostream>
    #include <iomanip>

    // Files
    #include "City.h"
    #include "Employee.h"
    #include "User.h"

    // Using
    using std::ostream;
    using std::cout;
    using std::endl;
    using std::setfill;
    using std::setw;
    using std::left;

    /**
     * Relationship matrix class
    */
    template <typename T>
    class Matrix {

        class Row {
            class Relation {

                int relation_strength;
                Relation* next_relation;

            public:
                Relation();
                ~Relation() = default;

                Relation* get_next_relation();
                int get_relation_strength();
                void set_next_relation( Relation* next );
                void set_relation_strength(int relation_strength );
            };

            T* elem;
            Relation* first_relation;
            Row* next_row;

            Relation* find_rel( int elem_i );

        public:

            Row( T* elem );
            ~Row();

            Row* get_next_row();
            T* get_elem();
            int get_relation( int elem_i );

            void set_next_row( Row* next );
            void set_elem( T* elem );
            bool set_relation( int i_elem, int strength );

            void uniformize( int size );
            Relation* find_relation( int i_elem );
            void remove_relations( int i_elem );
            void print_row( ostream& out );

        };

        int size;
        bool is_symmetrical;
        Row* first_row;
        Row* last_row;

        Row* find_row( int i_elem );

        void fill_rows();
        void empty_rows( int i_elem );

    public:

        Matrix( bool is_symmetrical );
        ~Matrix();

        /** Gets the index of the row where the element is in.
         * @warning The element used must be able to use the == operator
         * */
        int get_id( T elem );

        void add( T* elem );

        bool remove( int i_elem );

        bool modify( int i_first_elem, int i_second_elem, int strength );

        void print_matrix( ostream& out ) const;

        void operator+= ( T* elem );

        template <typename U>
        friend ostream& operator<< ( ostream& out, const Matrix<U>* matrix );

    };
    template class Matrix<City>;
    template class Matrix<User>;
    template class Matrix<Employee>;

#endif //RELATIONSHIP_MATRIX_MATRIX_H