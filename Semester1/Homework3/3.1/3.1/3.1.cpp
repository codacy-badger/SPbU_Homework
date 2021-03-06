#include "pch.h"
#include <stdio.h>
#include <cstdlib>

int arraySize(int mass[], int first, int last)
{
	return last - first + 1;
}

void insertionSort(int mass[], int low, int high)
{
	for (int i = low + 1; i <= high; ++i)
	{
		int help = mass[i];
		int j = i - 1;
		while ((j >= 0) && (mass[j] > help))
		{
			mass[j + 1] = mass[j];
			mass[j] = help;
			--j;
		}
	}
}

void swap(int mass[], int element1, int element2)
{
	int help = mass[element1];
	mass[element1] = mass[element2];
	mass[element2] = help;
}

int partition(int mass[], int low, int high)
{
	int pivot = mass[high];
	int i = low;

	for (int j = low; j <= high - 1; ++j)
	{
		if (mass[j] <= pivot)
		{
			swap(mass, i, j);
			++i;
		}
	}
	swap(mass, i, high);
	return i;
}

void quickSort(int mass[], int low, int high)
{
	if ((low < high) && (arraySize(mass, low, high) > 10))
	{
		int p = partition(mass, low, high);
		quickSort(mass, low, p - 1);
		quickSort(mass, p + 1, high);
	}
	else
	{
		insertionSort(mass, low, high);
	}
}

void test()
{
	int massTest[12]{ 4, 6, 8, 1, 9, 5, 1, 4, 2, 7, 12, 8 };
	quickSort(massTest, 0, 9);
	if ((massTest[3] == 4) && (massTest[4] == massTest[3]) && (massTest[2] < massTest[3]) && (massTest[8] > massTest[2]))
	{
		printf("Test passed\n");
	}
	else
	{
		printf("Test failed\n");
	}
	printf("\n");
}

int main()
{
	test();

	int n = 0;

	printf("Enter the number of elements in your massive ");
	scanf("%u", &n);

	int *mass = new int[n];

	for (int i = 0; i < n; ++i) // заполняем массив случайными числами
	{
		mass[i] = rand() % 11;
		printf("mass[%u] = %u\n", i, mass[i]);
	}
	printf("\n");

	quickSort(mass, 0, n - 1);

	for (int i = 0; i < n; ++i)
	{
		printf("mass[%u] = %u\n", i, mass[i]);
	}

	delete[] mass;
	return 0;
}