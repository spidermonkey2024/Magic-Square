#include <iostream>
#include <numeric>
#include <string>

constexpr int ROWS = 4;
constexpr int COLUMNS = 4;
constexpr int LIST_SIZE = 16;

typedef int matrix2d[ROWS][COLUMNS]; //2D array

void createArithmeticSeq(int arithSeq[], const int num_of_rows);
//Creates an arithmetic sequence

void matricize(int arithSeq[], matrix2d matrix, const int num_of_rows);
//Puts elements of1D array into a 2D array

void printMatrix(matrix2d matrix, const int num_of_rows);
//Prints a 2D array

void reverseDiagonal(matrix2d matrix, const int num_of_rows);
//Reverses the diagonals of a square matrix

void magicCheck(int arithSeq[], matrix2d matrix, const int listSize, const int num_of_rows);
//Checks whether 2D array is magic square

int main(int argc, char *argv[])
{
	int list[LIST_SIZE];
	int matrix[ROWS][COLUMNS];

	createArithmeticSeq(list, LIST_SIZE);
	matricize(list, matrix, ROWS);
	printMatrix(matrix, ROWS);
	reverseDiagonal(matrix, ROWS);
	printMatrix(matrix, ROWS);
	magicCheck(list, matrix, LIST_SIZE, ROWS);

	return 0;
}

void createArithmeticSeq(int arithSeq[], const int listSize)
{
	int first; //first number in arithmetic sequence
	int diff;  //arithmetic difference

	std::cout << "Enter first number: ";
	std::cin >> first;
	std::cout << "Enter the arithmetic difference: ";
	std::cin >> diff;

	//Generate arithmetic sequence
	for (auto i = 0; i < listSize; ++i)
	{
		arithSeq[i] = first + (i * diff);
	}

	//Output arithmetic sequence
	std::cout << "\nArithmetic sequence:\n";

	for (auto i = 0; i < LIST_SIZE; ++i)
	{
		std::cout << arithSeq[i] << " ";
	}
	std::cout << "\n";

} //end createArithmeticSeq

void matricize(int arithSeq[], matrix2d matrix, const int num_of_rows)
{
	for (auto i = 0; i < num_of_rows; ++i)
	{
		for (auto j = 0; j < num_of_rows; ++j)
		{
			matrix[i][j] = arithSeq[i * num_of_rows + j];
		}
	}

} //end matricize

void printMatrix(matrix2d matrix, const int num_of_rows)
{
	//Print the sequence
	std::cout << "\n2D array:\n";
	for (auto i = 0; i < num_of_rows; ++i)
	{
		for (auto j = 0; j < num_of_rows; ++j)
		{
			std::cout << " " << matrix[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "\n";
} //end printMatrix

void reverseDiagonal(matrix2d matrix, const int num_of_rows)
{
	auto lastRow = num_of_rows - 1; //last row of main matrix's diagonal

	//Reverse main diagonal
	for (auto row = 0; row < lastRow; ++row)
	{
		auto temp1 = matrix[row][row];
		lastRow = num_of_rows - row - 1;
		matrix[row][row] = matrix[lastRow][lastRow];
		matrix[lastRow][lastRow] = temp1;

		//Reverse second diagonal
		auto temp2 = matrix[lastRow][row];
		matrix[lastRow][row] = matrix[row][lastRow];
		matrix[row][lastRow] = temp2;
	}
} // end reverseDiagonal

void magicCheck(int arithSeq[], matrix2d matrix, const int listSize, const int num_of_rows)
{
	auto sequenceSum = std::accumulate(arithSeq, arithSeq + listSize, 0.0);
	auto magicNumber = sequenceSum / 4;

	auto majorDiagonalSum = static_cast<double>(0);
	auto minorDiagonalSum = static_cast<double>(0);

	for (auto i = 0; i < num_of_rows; ++i)
	{
		majorDiagonalSum += matrix[i][i];
		minorDiagonalSum += matrix[num_of_rows - i - 1][i];
	}

	//Check sum of each diagonal
	if (majorDiagonalSum != magicNumber || majorDiagonalSum != magicNumber)
	{
		std::cout << "It is not a magic number\n";
		return;
	}

	//Check sum of each row and column

	auto rowSum = static_cast<double>(0);
	auto columnSum = static_cast<double>(0);

	for (auto i = 0; i < num_of_rows; ++i)
	{
		for (auto j = 0; j < num_of_rows; ++j)
		{
			rowSum += matrix[i][j];
			columnSum += matrix[j][i];
		}

		if (rowSum != magicNumber || columnSum != magicNumber)
		{
			std::cout << "It is not a magic number\n";
			return;
		}
		rowSum = 0;
		columnSum = 0;
	}
	std::cout << "It is a magic square\n";
} //end magicCheck
