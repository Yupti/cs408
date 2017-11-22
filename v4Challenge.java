public class v4Challenge {

	private static final int row = 1000;
	private static final int col = 1000;
	private static final int row2 = 2000;
	private static final int col2 = 2000;
	private final double[][] data;
	private static v4Challenge M1, M2, M3, M4, M5;

	public v4Challenge(int row, int col) {
		data = new double[row][col];
		fill(this);
	}

	public static void add(v4Challenge A, v4Challenge B) {

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				M3.data[i][j] = A.data[i][j] + B.data[i][j];

	}

	public static void subtract(v4Challenge A, v4Challenge B) {

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				M4.data[i][j] = A.data[i][j] - B.data[i][j];
	}

	public static void multiply(v4Challenge A, v4Challenge B) {

		for (int i = 0; i < A.row; i++)
			for (int j = 0; j < B.col; j++)
				for (int k = 0; k < A.col; k++)
					M5.data[i][j] += A.data[i][k] * B.data[k][j];

	}


	public static void fill(v4Challenge M) {
		for (int i = 0; i < M.row; i++)
			for (int j = 0; j < M.col; j++)
				M.data[i][j] = 0.0;
	}


	public static void main(String[] args) {

		double startTime, endTime, duration;

		System.out.println("Timing for Version #4 Methods");
		System.out.println("Size for 1000 by 1000");
		M1 = new v4Challenge(row, col);
		M2 = new v4Challenge(row, col);
		M3 = new v4Challenge(row, col);
		M4 = new v4Challenge(row, col);
		M5 = new v4Challenge(row, col);


		startTime = System.currentTimeMillis();
		add(M1, M2);
		endTime = System.currentTimeMillis();
		System.out.println("That took " + (endTime - startTime) + " ms");

		startTime = System.currentTimeMillis();
		subtract(M1, M2);
		endTime = System.currentTimeMillis();
		System.out.println("That took " + (endTime - startTime) + " ms");

		startTime = System.currentTimeMillis();
		multiply(M1, M2);
		endTime = System.currentTimeMillis();
		System.out.println("That took " + (endTime - startTime) + " ms");

		System.out.println("Size for 2000 by 2000");
		M1 = new v4Challenge(row2, col2);
		M2 = new v4Challenge(row2, col2);
		M3 = new v4Challenge(row2, col2);
		M4 = new v4Challenge(row2, col2);
		M5 = new v4Challenge(row2, col2);

		startTime = System.currentTimeMillis();
		add(M1, M2);
		endTime = System.currentTimeMillis();
		System.out.println("That took " + (endTime - startTime) + " ms");

		startTime = System.currentTimeMillis();
		subtract(M1, M2);
		endTime = System.currentTimeMillis();
		System.out.println("That took " + (endTime - startTime) + " ms");

		startTime = System.currentTimeMillis();
		multiply(M1, M2);
		endTime = System.currentTimeMillis();
		System.out.println("That took " + (endTime - startTime) + " ms");

	}
}