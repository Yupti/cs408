#include <iostream>

using namespace std;

int r = 0, c = 0, r2 = 0, c2 = 0, init = 0, choice = 0;
double **M1, **M2, **M3 = 0, **M4 = 0, **M5 = 0;


void menu() {
	cout << "Enter choice:" << endl;
	cout << "(1) M3 = M1 + M2\n" << "(2) M4 = M1 - M2" << endl;
	cout << "(3) M5 = M1 * M2\n" << "(4) QUIT" << endl;
}


void printMatrix(double** matrix, int row, int col) {
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

void sum() {
	M3 = new double*[r];

	for (int i = 0; i < r; i++) {
		M3[i] = new double[c];
		for (int j = 0; j < c; j++) {
			M3[i][j] = M1[i][j] + M2[i][j];
		}
	}
}


void difference() {
	M4 = new double*[r];

	for (int i = 0; i < r; i++) {
		M4[i] = new double[c];
		for (int j = 0; j < c; j++) {
			M4[i][j] = M1[i][j] - M2[i][j];
		}
	}
}

void multiply() {
	M5 = new double*[r];

	for (int i = 0; i < r; i++) {
		M5[i] = new double[c2];  
		for (int j = 0; j < c2; j++) {    
			for (int inner = 0; inner < c; inner++) {  
				M5[i][j] += M1[i][inner] * M2[inner][j];  
			}    
		}   
	}
}

void preload() {
	r = 5, c = 5, r2 = 5, c2 = 5;

	M1 = new double*[r];
	for (int i = 0; i < r; i++) {
		*(M1 + i) = new double[c];
	}

	M1[0][0] = 1.0; M1[0][1] = 2.0; M1[0][2] = 3.0; M1[0][3] = 4.0; M1[0][4] = 5.0;
	M1[1][0] = 2.0; M1[1][1] = 2.0; M1[1][2] = 2.0; M1[1][3] = 2.0; M1[1][4] = 2.0;
	M1[2][0] = 3.0; M1[2][1] = 1.0; M1[2][2] = 1.0; M1[2][3] = 1.0; M1[2][4] = 3.0;
	M1[3][0] = 0.0; M1[3][1] = 0.0; M1[3][2] = 2.0; M1[3][3] - 3.0; M1[3][4] = -2.0;
	M1[4][0] = 4.0; M1[4][1] = 4.0; M1[4][2] = -4.0; M1[4][3] = 0.0; M1[4][4] = 0.0;

	M2 = new double*[r];
	for (int j  = 0; j < r; j++) {
		*(M2 + j) = new double[c2];
	}

	M2[0][0] = 1.0; M2[0][1] = 0.0; M2[0][2] = 0.0; M2[0][3] = 0.0; M2[0][4] = 0.0;
	M2[1][0] = 1.0; M2[1][1] = 2.0; M2[1][2] = 1.0; M2[1][3] = 2.0; M2[1][4] = 1.0;
	M2[2][0] = 0.0; M2[2][1] = 0.0; M2[2][2] = 1.0; M2[2][3] = 0.0; M2[2][4] = 0.0;
	M2[3][0] = 1.0; M2[3][1] = 1.0; M2[3][2] = 1.0; M2[3][3] = 1.0; M2[3][4] = 1.0;
	M2[4][0] = 2.0; M2[4][1] = 2.0; M2[4][2] = -2.0; M2[4][3] = 2.0; M2[4][4] = 2.0;
}

void userload() {
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
}

int main() {

	cout << "Enter (1) for preloaded matrix, or (2) for user input" << endl;
	cin >> init;

	switch (init) {
		case 1:
			preload();
			break;
		case 2:
			userload();
			break;
		default:
			preload();
			break;
	}

	do {
		menu();
		cin >> choice;

		switch (choice) {
			case 1:
				if (r == r2 && c == c2)
					sum();
				else
					cout << "Matrices are not of same dimensions, unable to perform addition." << endl;

				cout << "M1" << endl;
				printMatrix(M1, r, c);
				cout << "M2" << endl;
				printMatrix(M2, r, c);
				cout << "M3" << endl;
				printMatrix(M3, r, c);
				cout << "M4" << endl;
				printMatrix(M4, r, c);
				cout << "M5" << endl;
				printMatrix(M5, r, c2);

				break;
			case 2:
				if (r == r2 && c == c2) 
					difference();
				else
					cout << "Matrices are not of same dimensions, unable to perform subtraction." << endl;

				cout << "M1" << endl;
				printMatrix(M1, r, c);
				cout << "M2" << endl;
				printMatrix(M2, r, c);
				cout << "M3" << endl;
				printMatrix(M3, r, c);
				cout << "M4" << endl;
				printMatrix(M4, r, c);
				cout << "M5" << endl;
				printMatrix(M5, r, c2);
				break;
			case 3:
				if (c == r2)
					multiply();
				else
					cout << "Matrices are not of compatible dimensions, unable to perform multiplication." << endl;

				cout << "M1" << endl;
				printMatrix(M1, r, c);
				cout << "M2" << endl;
				printMatrix(M2, r, c);
				cout << "M3" << endl;
				printMatrix(M3, r, c);
				cout << "M4" << endl;
				printMatrix(M4, r, c);
				cout << "M5" << endl;
				printMatrix(M5, r, c2);

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
