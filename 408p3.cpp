#include <iostream>

using namespace std;

class Matrix {

	private:
		int row = 0;
		int col = 0;
		double** matrix;

	public:
		Matrix operator+(Matrix& m);
		Matrix operator-(Matrix& m);
		Matrix operator*(Matrix& m);
		void menu();
		void preload(int);
		void userload();
		void setRow(int);
		void setCol(int);
		int getRow();
		int getCol();

};

void Matrix::menu() {
	int loader = 0, loader2 = 0;

	cout << "Enter (1) for preload settings, or (2) for user input; if not, will default to preload M2." << endl;
	cin >> loader;

	switch (loader) {
		case 1:
			cout << "Enter (1) for M1 preset, or (2) for M2 preset; if not, will default to M2." << endl;
			cin >> loader2;
			preload(loader2);
			break;
		case 2:
			userload();
			break;
		default:
			preload(2);
			break;
	}
}

void Matrix::preload(int version) {
	row = 5;
	col = 5;

	if (version == 1) {
		matrix = new double*[row];
		for (int i = 0; i < row; i++) 
			*(matrix + i) = new double[col];

		matrix[0][0] = 1.0; matrix[0][1] = 2.0; matrix[0][2] = 3.0; matrix[0][3] = 4.0; matrix[0][4] = 5.0;
		matrix[1][0] = 2.0; matrix[1][1] = 2.0; matrix[1][2] = 2.0; matrix[1][3] = 2.0; matrix[1][4] = 2.0;
		matrix[2][0] = 3.0; matrix[2][1] = 1.0; matrix[2][2] = 1.0; matrix[2][3] = 1.0; matrix[2][4] = 3.0;
		matrix[3][0] = 0.0; matrix[3][1] = 0.0; matrix[3][2] = 2.0; matrix[3][3] - 3.0; matrix[3][4] = -2.0;
		matrix[4][0] = 4.0; matrix[4][1] = 4.0; matrix[4][2] = -4.0; matrix[4][3] = 0.0; matrix[4][4] = 0.0;
	}
	else {
		matrix = new double*[row];
		for (int j  = 0; j < row; j++) 
			*(matrix + j) = new double[col];

		matrix[0][0] = 1.0; matrix[0][1] = 0.0; matrix[0][2] = 0.0; matrix[0][3] = 0.0; matrix[0][4] = 0.0;
		matrix[1][0] = 1.0; matrix[1][1] = 2.0; matrix[1][2] = 1.0; matrix[1][3] = 2.0; matrix[1][4] = 1.0;
		matrix[2][0] = 0.0; matrix[2][1] = 0.0; matrix[2][2] = 1.0; matrix[2][3] = 0.0; matrix[2][4] = 0.0;
		matrix[3][0] = 1.0; matrix[3][1] = 1.0; matrix[3][2] = 1.0; matrix[3][3] = 1.0; matrix[3][4] = 1.0;
		matrix[4][0] = 2.0; matrix[4][1] = 2.0; matrix[4][2] = -2.0; matrix[4][3] = 2.0; matrix[4][4] = 2.0;
	}
}

void Matrix::userload() {
	cout << "Enter number of rows and columns respecitively, separated by a space for M1" << endl;
	cin >> row >> col;
	matrix = new double*[row];

	cout << "Enter all the values for the matrix of size: " << row << " by " << col << endl;
	for (int i = 0; i < row; i++) {
		matrix[i] = new double[col];
		for (int j = 0; j < col; j++) {
			cin >> matrix[i][j];
		}
	}
}

void Matrix::setRow(int r) {
	this->row = r;
}

void Matrix::setCol(int c) {
	this->col = c;
}

void Matrix::getRow() {
	return row;
}

void Matrix::getCol() {
	return col;
}

void Matrix::fill() {
	matrix = new double*[row];

	for (int i = 0; i < row; i++) {
		matrix[i] = new double*[col];
		for (int j = 0 j < col; j++)
			matrix[i][j] = 0.0;
	}
}

// THESE ARE GONNA NEED TESTING TO SEE IF ITS FINE
Matrix Matrix::operator+(Matrix& m) {
	if ((this->row == m.getRow()) && (this->col == m.getCol())) {
		Matrix newMatrix;
		newMatrix.setRow(row);
		newMatrix.setRow(col);
		newMatrix.fill();

		for (int i = 0; i < m.getRow(); i++) {
			for (int j = 0; j < m.getCol(); j++) {
				*(*(newMatrix.matrix+i)+j) = *(*(matrix+i)+j) + *(*(m.matrix+i)+j);
			}
		}

		return newMatrix;
	}
	else {
		cout << "Unable to perform addition operation, setting values to M1 values." << endl;
		return matrix;
	}
}

Matrix Matrix::operator-(Matrix& m) {
	if ((this->row == m.getRow()) && (this->col == m.getCol())) {
		Matrix newMatrix;
		newMatrix.setRow(row);
		newMatrix.setRow(col);
		newMatrix.fill();

		for (int i = 0; i < m.getRow(); i++) {
			for (int j = 0; j < m.getCol(); j++) {
				*(*(newMatrix.matrix+i)+j) = *(*(matrix+i)+j) - *(*(m.matrix+i)+j);
			}
		}

		return newMatrix;
	}
	else {
		cout << "Unable to perform subtraction operation, setting values to M1 values." << endl;
		return matrix;
	}
	
}

Matrix Matrix::operator*(Matrix& m) {
	if (this->col == m.getRow()) {
		Matrix newMatrix;
		newMatrix.setRow(row);
		newMatrix.setCol(m.getCol());
		newMatrix.fill();

		for (int i = 0; i < this->getRow(); i++) {
			for (int j = 0; i < m.getCol(); j++) {
				for (int k = 0; k < this->getCol(); k++) {
					*(*(newMatrix.matrix+i)+j) += *(*(matrix+i)+k) * *(*(m.matrix+k)+j);
				}
			}
		}
	}
	else {
		cout << "Unable to perform multiplication operation, settings values to M1 values." << endl;
		return matrix;
	}
}
