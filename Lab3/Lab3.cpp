#include <stdlib.h>
#include <stdio.h>
#include "time.h"
void swap(int* a, int* b) 
{
	int mem = *a;
	*a = *b;
	*b = mem;
} // Меняем местами
void sort(int* arr, int size) { // Сортировка выбором
	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (arr[j] > arr[min_idx])
				min_idx = j;
		swap(&arr[min_idx], &arr[i]);
	}
}
void vivod(int* arr, int size) { 
	for (int i = 0; i < size; i++)
		printf("[1][%d]:%d ", i + 1, arr[i]);
} // Вывод массива
int main()
{
	srand(time(NULL));
	int sizeN, sizeM;
	printf("Enter size of N array:");
	scanf_s("%d", &sizeN);
	int* Narr = (int*)calloc(sizeN, sizeof(int));
	for (int i = 0; i < sizeN; i++)
		Narr[i] = rand() % 100;
	sort(Narr, sizeN);
	vivod(Narr, sizeN);
	printf("\n\nEnter size of M array:");
	scanf_s("%d", &sizeM);
	int* Marr = (int*)calloc(sizeM, sizeof(int));
	for (int i = 0; i < sizeM; i++)
		Marr[i] = rand() % 100;
	sort(Marr, sizeM);
	vivod(Marr, sizeM);
	int* commarr = (int*)calloc(sizeM + sizeN, sizeof(int));
	for (int i = 0; i < sizeN; i++)
		commarr[i] = Narr[i];
	for (int i = sizeN; i < sizeN + sizeM; i++)
		commarr[i] = Marr[i - sizeN];
	printf("\n\nCommon array:\n");
	sort(commarr, sizeN + sizeM);
	vivod(commarr, sizeN + sizeM);
	printf("\n\nTransposed matrix:\n");
	int** transposed = (int**)calloc(sizeN + sizeM, sizeof(int));
	int* rows = (int*)malloc(sizeof(int));
	for (int i = 0; i < sizeN + sizeM; i++)
	{
		transposed[i] = (int*)calloc(1, sizeof(int));
		transposed[i][0] = commarr[i];
	}
	for (int i = 0; i < sizeN + sizeM; i++)
	{
		transposed[i][0] = commarr[i];
		printf("[%d][1]: %d\n", i + 1, transposed[i][0]);
		free(transposed[i]);
	}
	free(Narr); free(Marr); free(commarr); 
	free(transposed); free(rows);
	printf("\n\n");
	return 0;
}

