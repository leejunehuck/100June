#include <stdio.h>
#include <stdlib.h>

int** InputMatrix(int row, int col); //input ют╥б
void PrintMatrix(int ***matrix, int row, int col);
int** MallocMatrix(int row, int col);
int** FreeMatrix(int*** matrix, int row);

int** MallocMatrix(int row, int col)
{
	int** matrix = (int**)malloc(sizeof(int*) * row);
	for (int i = 0; i < row; i++)
	{
		matrix[i] = (int*)malloc(sizeof(int) * col);
	}
	return matrix;
}

int** FreeMatrix(int*** matrix, int row)
{
	for (int i = 0; i < row; i++)
	{
		free((*matrix)[i]);
	}
	free(*matrix);
}

int** InputMatrix(int row, int col)
{
	int** matrix = MallocMatrix(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	return matrix;
}

void PrintMatrix(int*** matrix, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", (*matrix)[i][j]);
		}
		printf("\n");
	}
}


int main()
{ 
	int row1, col1,row2,col2;
	scanf("%d %d", &row1, &col1);
	row2 = row1;
	col2 = col1;
	int** matrix1 = InputMatrix(row1,col1);
	int** matrix2 = InputMatrix(row2, col2);
	int** resultmatrix = MallocMatrix(row1, col2);

	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			resultmatrix[i][j] = 0;
			resultmatrix[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	PrintMatrix(&resultmatrix, row1, col2);
	FreeMatrix(&matrix1, row1);
	FreeMatrix(&matrix2, row2);
	FreeMatrix(&resultmatrix, row1);
	return 0;
}
