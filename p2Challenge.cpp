#include <iostream>
#include <ctime>

using namespace std;

int r = 0, c = 0, r2 = 0, c2 = 0, init = 0, choice = 0;
double **M1, **M2, **M3 = 0, **M4 = 0, **M5 = 0;

void sum() {

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			M3[i][j] = M1[i][j] + M2[i][j];
		}
	}
}


void difference() {

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			M4[i][j] = M1[i][j] - M2[i][j];
		}
	}
}

void multiply() {

	for (int i = 0; i < r; i++) {  
		for (int j = 0; j < c2; j++) {    
			for (int inner = 0; inner < c; inner++) {  
				M5[i][j] += M1[i][inner] * M2[inner][j];  
			}    
		}   
	}
}

void size1000() {
	r = c = r2 = c2 = 1000;

	M1 = new double*[r];
	for (int i = 0; i < r; i++) {
		*(M1 + i) = new double[c];
	}
	M2 = new double*[r];
	for (int i = 0; i < r; i++) {
		*(M2 + i) = new double[c];
	}
	M3 = new double*[r];
	for (int i = 0; i < r; i++) {
		*(M3 + i) = new double[c];
	}
	M4 = new double*[r];
	for (int i = 0; i < r; i++) {
		*(M4 + i) = new double[c];
	}
	M5 = new double*[r];
	for (int i = 0; i < r; i++) {
		*(M5 + i) = new double[c];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			M1[i][j] = 0;
			M2[i][j] = 0;
			M3[i][j] = 0;
			M4[i][j] = 0;
			M5[i][j] = 0;
		}
	}
}

void size2000() {
	r = c = r2 = c2 = 2000;

	M1 = new double*[r];
	for (int i = 0; i < r; i++) {
		*(M1 + i) = new double[c];
	}
	M2 = new double*[r];
	for (int i = 0; i < r; i++) {
		*(M2 + i) = new double[c];
	}
	M3 = new double*[r];
	for (int i = 0; i < r; i++) {
		*(M3 + i) = new double[c];
	}
	M4 = new double*[r];
	for (int i = 0; i < r; i++) {
		*(M4 + i) = new double[c];
	}
	M5 = new double*[r];
	for (int i = 0; i < r; i++) {
		*(M5 + i) = new double[c];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			M1[i][j] = 0;
			M2[i][j] = 0;
			M3[i][j] = 0;
			M4[i][j] = 0;
			M5[i][j] = 0;
		}
	}
}

int main() {

	std::clock_t start;

	std::cout << "Timing for Version #2 Methods" << std::endl;
	std::cout << "Size for 1000 by 1000" << std::endl;
	size1000();
	std::cout << "Addition" << std::endl;
	start = std::clock();
	sum();
	std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
	std::cout << "Subtraction" << std::endl;
	start = std::clock();
	difference();
	std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
	std::cout << "Multiplication" << std::endl;
	start = std::clock();
	multiply();
	std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

	std::cout << "Size for 2000 by 2000" << std::endl;
	size2000();
	std::cout << "Addition" << std::endl;
	start = std::clock();
	sum();
	std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
	std::cout << "Subtraction" << std::endl;
	start = std::clock();
	difference();
	std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
	std::cout << "Multiplication" << std::endl;
	start = std::clock();
	multiply();
	std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
	return 0;
}