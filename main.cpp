
#include <iostream>

#include "./Headers/Matrix.h"

int main() {
	Matrix<int>* m = new Matrix<int>( false );
	int* value = new int( 3 );
	*m += value;
	std::cout << m;
	return 0;
}
