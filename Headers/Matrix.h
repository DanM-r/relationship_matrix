#ifndef MATRIX_H
#define MATRIX_H
	
	// Libraries
	#include <iostream>
	#include <iomanip>
	
	// Files
	
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

				int relation_strenght;
				Relation* next;

				public:

					Relation();
					~Relation();

					Relation* get_next();
					int get_relation_strenght();

					void set_next( Relation* next );
					void set_relation_strenght( int relation_strenght );

			};

			T* elem;
			Relation* first_relation;
			Row* next;

			Relation* find_rel( int elem_i );

			public:

				Row( T* elem );
				~Row();

				Row* get_next();
				T* get_elem();
				int get_relation( int elem_i );

				void set_next( Row* next );
				void set_elem( T* elem );
				bool set_relation( int i_elem, int strength );

				void uniformize( int size );
				void print_row( ostream& out );

		};
		
		int size;
		bool is_symmetrical;
		Row* first_row;
		Row* last_row;

		Row* find_row( int i_elem );

		void fill_rows();

		public:

			Matrix( bool is_symmetrical );
			~Matrix();

			void add( T* elem );

			bool remove( int i_elem );

			bool modify( int i_first_elem, int i_second_elem, int strength );

			void print_matrix( ostream& out );

			void operator+= ( T* elem );

			template <typename U>
			friend ostream& operator<< ( ostream& out, const Matrix<U>* matrix );
	
	};
		
	template class Matrix<int>;

#endif
