#ifndef MATRIX_H
#define MATRIX_H
	
	// Libraries
	
	// Files
	
	// Using
	
	template <typename Element>
	class Matrix {

		class Row {

			class Relationship {

				int value;
				Relationship* next;

				public:

					Relationship();
					~Relationship();

					Relationship* get_next();
					void set_next( Relationship* next );

			};

			int size;
			Element* element;
			Relationship* first_collumn;
			Row* next;

			/**
			 * Initializes the relationship values given the size number
			*/
			void init_relationships();

			public:

				Row( Element* element, int size );
				~Row();

				Row* get_next();
				void set_next( Row* next );
				
				/**
				 * Removes the 
				*/
				bool remove( int collumn );

		};
		
		int size;
		bool is_symmetrical;
		Row* first_row;
		Row* bottom_row;

		public:

			Matrix( int size, bool is_symmetrical );
			~Matrix();

			/**
			 * Adds an element to the matrix.
			 * 
			 * @param new_element The element to be added.
			*/
			void add( Element* new_element );

			/**
			 * Extracts an element from the matrix.
			 * 
			 * @param row_index the row of the element
			 * @return The element that was taken.
			*/
			Element* remove( int row_index );

			/**
			 * Finds the element of a row.
			 * 
			 * @param row_index the index to the row where the element is stored.
			 * @return The element of the row.
			*/
			Element* find_element( int row_index );

			/**
			 * Finds the row
			 * 
			 * @param row_index the index to the row.
			 * @return the row to the index.
			*/
			Row* find_row( int row_index );

			/**
			 * Modifies the relationship value
			 * 
			 * @param row the row of the element
			 * @param collumn the collumn of the relatonship
			 * @param modified_relationship the new value of the relationship.
			 * @return true if the modification was succesfull, false otherwise.
			*/
			bool modify( int row, int collumn, int modified_relationship );
	
	};

	//template class Matrix<int>;

#endif
