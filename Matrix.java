import java.util.Scanner;

public class Matrix {

	private String name;
	private static final int row = 5;
	private static final int col = 5;
	private final double[][] data;
	private static Matrix M1, M2, M3, M4, M5;

	public Matrix() {
		data = new double[row][col];
		fill(this);
	}

	public Matrix(double [][] preset) {
		data = new double[row][col];
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				data[i][j] = preset[i][j];

	}

	public void setName(String newName) {
		name = newName;
	}

	public String getName() {
		return name;
	}

	public static Matrix add(Matrix A, Matrix B) {
		if (A.row == B.row && A.col == B.col) {
			Matrix C = new Matrix();
			C.setName("M3");

			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					C.data[i][j] = A.data[i][j] + B.data[i][j];

			return C;
		}
		else {
			System.out.println("Dimensions are incompatible, returning values of M1");
			return A;
		}
	}

	public static Matrix subtract(Matrix A, Matrix B) {
		if (A.row == B.row && A.col == B.col) {
			Matrix C = new Matrix();
			C.setName("M4");

			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					C.data[i][j] = A.data[i][j] - B.data[i][j];

			return C;
		}
		else {
			System.out.println("Dimensions are incompatible, returning values of M1");
			return A;
		}
	}

	public static Matrix multiply(Matrix A, Matrix B) {

		if (A.col == B.row) {
			Matrix C = new Matrix();
			C.setName("M5");

			for (int i = 0; i < A.row; i++)
				for (int j = 0; j < B.col; j++)
					for (int k = 0; k < A.col; k++)
						C.data[i][j] += A.data[i][k] * B.data[k][j];

			return C;
		}
		else {
			System.out.println("Dimensions are incompatible, returning values of M1");
			return A;
		}
	}

	public static void printMatrix(Matrix M) {
		System.out.println("Matrix: " + M.getName());
		for (int i = 0; i < M.row; i++) {
			for (int j = 0; j < M.col; j++) {
				System.out.print(M.data[i][j] + " ");
			}
			System.out.println("");
		}
		System.out.println("");

	}

	public static void fill(Matrix M) {
		for (int i = 0; i < M.row; i++)
			for (int j = 0; j < M.col; j++)
				M.data[i][j] = 0.0;
	}

	public static void menu() {
		System.out.println("Please choose an action: ");
		System.out.println("(1) M3 = M1 + M2");
		System.out.println("(2) M4 = M1 - M2");
		System.out.println("(3) M5 = M1 * M2");
		System.out.println("(4) QUIT");
	}

	public static void main(String[] args) {

		Scanner keyboard = new Scanner(System.in);
		int choice = 0;

		double[][] M1data = {{1.0, 2.0, 3.0, 4.0, 5.0},
							{2.0, 2.0, 2.0, 2.0, 2.0},
							{3.0, 1.0, 1.0, 1.0, 3.0},
							{0.0, 0.0, 2.0, 3.0, -2.0},
							{4.0, 4.0, -4.0, 0.0, 0.0} 
							};

		double[][] M2data = {{1.0, 0.0, 0.0, 0.0, 0.0},
							{1.0, 2.0, 1.0, 2.0, 1.0},
							{0.0, 0.0, 1.0, 0.0, 0.0},
							{1.0, 1.0, 1.0, 1.0, 1.0},
							{2.0, 2.0, -2.0, 2.0, 2.0}
							};

		M1 = new Matrix(M1data);
		M1.setName("M1");
		M2 = new Matrix(M2data);
		M2.setName("M2");
		M3 = new Matrix();
		M3.setName("M3");
		M4 = new Matrix();
		M4.setName("M4");
		M5 = new Matrix();
		M5.setName("M5");

		do {
			menu();
			choice = keyboard.nextInt();

			switch (choice) {
				case 1:	
						M3 = add(M1, M2);
						break;
				case 2:	
						M4 = subtract(M1, M2);
						break;
				case 3:	
						M5 = multiply(M1, M2);
						break;
				case 4:	
						System.out.println("Thank you for using this program!");
						break;
				default:
						System.out.println("Incorrect choice, please try again.");
						break;
			}

			if (choice > 0 && choice < 4) {
				printMatrix(M1);
				printMatrix(M2);
				printMatrix(M3);
				printMatrix(M4);
				printMatrix(M5);
			}

		} while (choice != 4);

		keyboard.close();

	}
}