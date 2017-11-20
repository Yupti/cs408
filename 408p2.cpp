#include <iostream>

using namespace std;

void menu() {
	cout << "Enter choice:" << endl;
	cout << "(1) M3 = M1 + M2\n" << "(2) M4 = M1 - M2" << endl;
	cout << "(3) M5 = M1 * M2\n" << "(4) QUIT" << endl;
}


void printMatrix2(double** matrix, int row, int col) {
	if (matrix == 0)
		cout << "Matrix not created yet." << endl;
	else {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}	
}

double** sum(double** M1, double** M2, int row, int col) {
	double** new2Darray = 0;
	new2Darray = new double*[row];

	for (int i = 0; i < row; i++) {
		new2Darray[i] = new double[col];
		for (int j = 0; j < col; j++) {
			new2Darray[i][j] = M1[i][j] + M2[i][j];
		}
	}

	return new2Darray;
}


double** difference(double** M1, double** M2, int row, int col) {
	double** new2Darray = 0;
	new2Darray = new double*[row];

	for (int i = 0; i < row; i++) {
		new2Darray[i] = new double[col];
		for (int j = 0; j < col; j++) {
			new2Darray[i][j] = M1[i][j] - M2[i][j];
		}
	}

	return new2Darray;
}

double** multiply(double** M1, double** M2, int row, int col, int col2) {
	double** new2Darray = 0;
	new2Darray = new double*[row];

	for (int i = 0; i < row; i++) {
		new2Darray[i] = new double[col];  
		for (int j = 0; j < col2; j++) {  
			// Multiply the row of A by the column of B to get the row, column of product.  
			for (int inner = 0; inner < col; inner++) {  
				new2Darray[i][j] += M1[i][inner] * M2[inner][j];  
			}    
		}   
	}

	return new2Darray;
}


int main() {

	int r = 0, c = 0, r2 = 0, c2 = 0, choice = 0;
	double** M3 = 0;
	double** M4 = 0;
	double** M5 = 0;

	cout << "Enter number of rows and columns respecitively, separated by a space for M1" << endl;
	cin >> r >> c;
	double** M1 = new double*[r];

	cout << "Enter all the values for the matrix of size: " << r << " by " << c << endl;
	for (int i = 0; i < r; i++) {
		M1[i] = new double[c];
		for (int j = 0; j < c; j++) {
			cin >> M1[i][j];
		}
	}

	//printMatrix2(M1, r, c); // good for pointer to pointer arrays, like so

	cout << "Enter number of rows and columns respecitively, separated by a space for M2" << endl;
	cin >> r2 >> c2;
	double** M2 = new double*[r2];

	cout << "Enter all the values for the matrix of size: " << r2 << " by " << c2 << endl;
	for (int i = 0; i < r2; i++) {
		M2[i] = new double[c2];
		for (int j = 0; j < c2; j++) {
			cin >> M2[i][j];
		}
	}

	// ADD/SUBT: IF R != R2 AND C != C2, DOES NOT WORK
	// MULT: IF C != R2, DOES NOT WORK
	do {
		menu();
		cin >> choice;

		switch (choice) {
			case 1:
				if (r == r2 && c == c2)
					M3 = sum(M1, M2, r, c);
				else
					cout << "Matrices are not of same dimensions, unable to perform addition." << endl;

				cout << "M1" << endl;
				printMatrix2(M1, r, c);
				cout << "M2" << endl;
				printMatrix2(M2, r, c);
				cout << "M3" << endl;
				printMatrix2(M3, r, c);
				cout << "M4" << endl;
				printMatrix2(M4, r, c);
				cout << "M5" << endl;
				printMatrix2(M5, r, c2);

				break;
			case 2:
				if (r == r2 && c == c2) 
					M4 = difference(M1, M2, r, c);
				else
					cout << "Matrices are not of same dimensions, unable to perform subtraction." << endl;

				cout << "M1" << endl;
				printMatrix2(M1, r, c);
				cout << "M2" << endl;
				printMatrix2(M2, r, c);
				cout << "M3" << endl;
				printMatrix2(M3, r, c);
				cout << "M4" << endl;
				printMatrix2(M4, r, c);
				cout << "M5" << endl;
				printMatrix2(M5, r, c2);
				break;
			case 3:
				if (c == r2)
					M5 = multiply(M1, M2, r, c, c2);
				else
					cout << "Matrices are not of compatible dimensions, unable to perform multiplication." << endl;

				cout << "M1" << endl;
				printMatrix2(M1, r, c);
				cout << "M2" << endl;
				printMatrix2(M2, r, c);
				cout << "M3" << endl;
				printMatrix2(M3, r, c);
				cout << "M4" << endl;
				printMatrix2(M4, r, c);
				cout << "M5" << endl;
				printMatrix2(M5, r, c2);

				break;
			case 4:
				cout << "Thank you for using this program!" << endl;
				break;
			default:
				cout << "Incorrect choice used, please try again." << endl;
				break;
		}
	} while (choice != 4);

	return 0;
}
