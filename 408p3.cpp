#include <iostream>

using namespace std;

class Matrix {

	private:
		double** matrix;

	public:
		Matrix operator+();
		Matrix operator-();
		Matrix operator*();
};