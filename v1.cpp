#include <iostream>

using namespace std;

const int ROWS = 5;
const int COLS = 5;

double M1[ROWS][COLS] = {{1.0, 2.0, 3.0, 4.0, 5.0},
						 {2.0, 2.0, 2.0, 2.0, 2.0},
						 {3.0, 1.0, 1.0, 1.0, 3.0},
						 {0.0, 0.0, 2.0, 3.0, -2.0},
						 {4.0, 4.0, -4.0, 0.0, 0.0}
						};
double M2[ROWS][COLS] = {{1.0, 0.0, 0.0, 0.0, 0.0},
						 {1.0, 2.0, 1.0, 2.0, 1.0},
						 {0.0, 0.0, 1.0, 0.0, 0.0},
						 {1.0, 1.0, 1.0, 1.0, 1.0},
						 {2.0, 2.0, -2.0, 2.0, 2.0}
						};
double M3[ROWS][COLS] = {{0}};
double M4[ROWS][COLS] = {{0}};
double M5[ROWS][COLS] = {{0}};

void menu() {
	cout << "Enter choice:" << endl;
	cout << "(1) M3 = M1 + M2\n" << "(2) M4 = M1 - M2" << endl;
	cout << "(3) M5 = M1 * M2\n" << "(4) QUIT" << endl;
}

void printMatrix(double matrix[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}	
}

void sum() {

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			M3[i][j] = M1[i][j] + M2[i][j];
		}
	}

	cout << "Printing Matrices:" << endl;
	cout << "M1" << endl;
	printMatrix(M1);
	cout << "M2" << endl;
	printMatrix(M2);
	cout << "M3" << endl;
	printMatrix(M3);
	cout << "M4" << endl;
	printMatrix(M4);
	cout << "M5" << endl;
	printMatrix(M5);
}

void difference() {

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			M4[i][j] = M1[i][j] - M2[i][j];
		}
	}

	cout << "Printing Matrices:" << endl;
	cout << "M1" << endl;
	printMatrix(M1);
	cout << "M2" << endl;
	printMatrix(M2);
	cout << "M3" << endl;
	printMatrix(M3);
	cout << "M4" << endl;
	printMatrix(M4);
	cout << "M5" << endl;
	printMatrix(M5);
}

void multiply() {

	for (int i = 0; i < ROWS; i++) {  
		for (int j = 0; j < COLS; j++) {   
			for (int inner = 0; inner < COLS; inner++) {  
				M5[i][j] += M1[i][inner] * M2[inner][j];  
			}    
		}   
	}

	cout << "Printing Matrices:" << endl;
	cout << "M1" << endl;
	printMatrix(M1);
	cout << "M2" << endl;
	printMatrix(M2);
	cout << "M3" << endl;
	printMatrix(M3);
	cout << "M4" << endl;
	printMatrix(M4);
	cout << "M5" << endl;
	printMatrix(M5);
}

int main() {

	int choice = 0;

	do {
		menu();
		cin >> choice;

		switch (choice) {
			case 1:
				sum();
				break;
			case 2:
				difference();
				break;
			case 3:
				multiply();
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
