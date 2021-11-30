#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int calculationElement(int* matrix1, int** matrix2, int columns, int columnOfMatrix2) { // Подсчёт одного элемента
	int mem = 0;
	for (int i = 0; i < columns; i++)
		mem += matrix1[i] * matrix2[i][columnOfMatrix2];
	return mem;
}

void fillingMatrix(int** matrix, int rows, int column) { // Заполнение матриц
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < column; j++)
			matrix[i][j] = rand() % 10 + 1;
}

int** creatingMatrix(int rows, int columns) { // Создание матрицы
	int** matrix = (int**)calloc(rows, sizeof(int));
	for (int i = 0; i < rows; i++) 
		matrix[i] = (int*)calloc(columns, sizeof(int));
	
	return matrix;
}
void deletingMatrix(int** matrix, int rows) { // Удаление матрицы
	for (int i = 0; i < rows; i++)
		free(matrix[i]);
	free(matrix);
}

void vivod(const char title[], int** matrix, int rows, int columns) { // Вывод матрицы
	printf("%s:\n", title);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
	printf("\n");
}

int** multiplicationMatrix(int** matrix, int** matrix2, int rows1, int columns1, int rows2, int columns2) { // Умножение матриц
	if (columns1 != rows2) {
		int** newMatrix = NULL;
		return newMatrix;
	}
	int** newMatrix = creatingMatrix(rows1, columns2);
	for (int i = 0; i < rows1; i++)
		for (int j = 0; j < columns2; j++)
			newMatrix[i][j] = calculationElement(matrix[i], matrix2, columns1, j);
	return newMatrix;
}

int main()
{
	int rows1, columns1, rows2, columns2;
	printf("Enter rows for matrix 1: ");
	scanf("%d", &rows1);
	printf("Enter columns for matrix 1: ");
	scanf("%d", &columns1);
	printf("Enter rows for matrix 2: ");
	scanf("%d", &rows2);
	printf("Enter columns for matrix 2: ");
	scanf("%d", &columns2);
	printf("\n");
	srand(time(NULL));

	int** matrix1 = creatingMatrix(rows1, columns1);
	int** matrix2 = creatingMatrix(rows2, columns2);
	fillingMatrix(matrix1, rows1, columns1);
	fillingMatrix(matrix2, rows2, columns2);
	vivod("Matrix #1", matrix1, rows1, columns1);
	vivod("Matrix #2", matrix2, rows2, columns2);
	int** newMatrix = multiplicationMatrix(matrix1, matrix2, rows1, rows2, columns1, columns2);

	if (newMatrix == NULL)
		printf("Multiplication can't be done!\n");
	else
		vivod("New matrix", newMatrix, rows1, columns2);

	deletingMatrix(matrix1, rows1);
	deletingMatrix(matrix2, rows2);
	if (newMatrix != NULL)
		deletingMatrix(newMatrix, rows1);
	printf("\n\n");
}
