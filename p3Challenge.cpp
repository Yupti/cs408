#include <iostream>
#include <ctime>

using namespace std;

class Matrix {

	private:
		int row;
		int col;
		string mName;
		double** matrix;

	public:
		Matrix(); 
		Matrix operator+(Matrix& m);
		Matrix operator-(Matrix& m);
		Matrix operator*(Matrix& m);
		//void menu();
		//void preload(int);
		//void userload();
		void setName(string);
		void setRow(int);
		void setCol(int);
		void size1000();
		void size2000();
		string getName();
		int getRow();
		int getCol();

};

Matrix::Matrix() {
	mName = "test";
	row = 0;
	col = 0;
	matrix = 0;
}

void Matrix::setRow(int r) {
	this->row = r;
}

void Matrix::setCol(int c) {
	this->col = c;
}

void Matrix::setName(string name) {
	this->mName = name;
}

int Matrix::getRow() {
	return row;
}

int Matrix::getCol() {
	return col;
}

string Matrix::getName() {
	return mName;
}

void Matrix::size1000() {
	
	row = 1000;
	col = 1000;

	matrix = new double*[row];
	for (int i = 0; i < row; i++)
		*(matrix+i) = new double[col];

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix[i][j] = 0.0;
		}
	}

}

void Matrix::size2000() {

	row = 2000;
	col = 2000;

	matrix = new double*[row];
	for (int i = 0; i < row; i++)
		*(matrix+i) = new double[col];

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix[i][j] = 0.0;
		}
	}
}

Matrix Matrix::operator+(Matrix& m) {
	if ((this->row == m.getRow()) && (this->col == m.getCol())) {
		Matrix newMatrix;
		newMatrix.setRow(row);
		newMatrix.setRow(col);
		newMatrix.setName("M3");

		newMatrix.matrix = new double*[row];
		for (int i = 0; i < row; i++)
			*(newMatrix.matrix+i) = new double[col];

		for (int i = 0; i < m.getRow(); i++) {
			for (int j = 0; j < m.getCol(); j++) {
				newMatrix.matrix[i][j] = matrix[i][j] + m.matrix[i][j]; 
			}
		}

		/*cout << newMatrix.getName() << endl;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << newMatrix.matrix[i][j] << " ";
			}
			cout << endl;
		}*/
		
		return newMatrix;
	}
	else {
		cout << "Unable to perform addition operation, setting values to M2 values." << endl;
		return m;
	}
}

Matrix Matrix::operator-(Matrix& m) {
	if ((this->row == m.getRow()) && (this->col == m.getCol())) {
		Matrix newMatrix;
		newMatrix.setRow(row);
		newMatrix.setRow(col);
		newMatrix.setName("M4");

		newMatrix.matrix = new double*[row];
		for (int i = 0; i < row; i++)
			*(newMatrix.matrix+i) = new double[col];

		for (int i = 0; i < m.getRow(); i++) {
			for (int j = 0; j < m.getCol(); j++) {
				newMatrix.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
			}
		}

		/*cout << newMatrix.getName() << endl;

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << newMatrix.matrix[i][j] << " ";
			}
			cout << endl;
		}*/

		return newMatrix;
	}
	else {
		cout << "Unable to perform subtraction operation, setting values to M2 values." << endl;
		return m;
	}
	
}

Matrix Matrix::operator*(Matrix& m) {
	if (this->col == m.getRow()) {
		Matrix newMatrix;
		newMatrix.setRow(row);
		newMatrix.setCol(m.getCol());
		newMatrix.setName("M5");
		
		newMatrix.matrix = new double*[row];
		for (int i = 0; i < row; i++)
			*(newMatrix.matrix+i) = new double[m.getCol()];

		for (int i = 0; i < row; i++) 
			for (int j = 0; j < col; j++)
				newMatrix.matrix[i][j] = 0.0;

		for (int i = 0; i < this->getRow(); i++) {
			for (int j = 0; j < m.getCol(); j++) {
				for (int k = 0; k < this->getCol(); k++) {
					newMatrix.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
				}
			}
		}

		/*cout << newMatrix.getName() << endl;

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << newMatrix.matrix[i][j] << " ";
			}
			cout << endl;
		}*/

		return newMatrix;
	}
	else {
		cout << "Unable to perform multiplication operation, settings values to M2 values." << endl;
		return m;
	}
}


int main() {

	Matrix M1 = Matrix();
	M1.setName("M1");
	Matrix M2 = Matrix();
	M2.setName("M2");
	Matrix M3 = Matrix();
	M3.setName("M3");
	Matrix M4 = Matrix();
	M4.setName("M4");
	Matrix M5 = Matrix();
	M5.setName("M5");

	std::clock_t start;

	std::cout << "Timing for Version #3 Methods" << std::endl;
	std::cout << "Size for 1000 by 1000" << std::endl;
	M1.size1000();
	M2.size1000();
	M3.size1000();
	M4.size1000();
	M5.size1000();
	std::cout << "Addition" << std::endl;
	start = std::clock();
	M3 = M1 + M2;
	std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
	std::cout << "Subtraction" << std::endl;
	start = std::clock();
	M4 = M1 - M2;
	std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
	std::cout << "Multiplication" << std::endl;
	start = std::clock();
	M5 = M1 * M2;
	std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

	std::cout << "Size for 2000 by 2000" << std::endl;
	M1.size2000();
	M2.size2000();
	M3.size2000();
	M4.size2000();
	M5.size2000();
	std::cout << "Addition" << std::endl;
	start = std::clock();
	M3 = M1 + M2;
	std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
	std::cout << "Subtraction" << std::endl;
	start = std::clock();
	M4 = M1 - M2;
	std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
	std::cout << "Multiplication" << std::endl;
	start = std::clock();
	M5 = M1 * M2;
	std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

	return 0;
}