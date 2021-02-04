#include <iostream>
using namespace std;
void RotateOuterLayer(int **matrix, int rows, int cols);
int main()
{

	int rows;
	cin >> rows;
	cout << endl;

	int cols;
	cin >> cols;
	cout << endl;
	int **matrix = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = rand() % 10;
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << " ";
		}

		cout << endl;

	}

	cout << endl;

	RotateOuterLayer(matrix, rows, cols);
		
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << " ";
		}

		cout << endl;

	}


	for (int i = 0; i < rows; i++)
	{
		delete[]matrix[i];
		matrix[i] = nullptr;
	}

	delete[]matrix;
	matrix = nullptr;

	return 0;

}

void RotateOuterLayer(int **matrix, int rows, int cols)
{
	int temp = matrix[0][cols - 1];
	
	for (int i = cols - 1 ; i > 0; i--)
	{
		matrix[0][i] = matrix[0][i - 1];
	}

	for (int i = 0; i < rows - 1; i++)
	{
		matrix[i][0] = matrix[i + 1][0];
	}

	for (int i = 0; i < cols - 1; i++)
	{

		matrix[rows - 1][i] = matrix[rows - 1][i + 1];
	}

	for (int i = rows - 1; i > 0; i--)
	{
		matrix[i][cols - 1] = matrix[i - 1][cols - 1];
	}

	matrix[1][cols - 1] = temp;
	

}
