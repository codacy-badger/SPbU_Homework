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

bool binarySearch(int mass[], int high, int value)
{
	int right = high;
	int left = 0;
	bool index = false;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (mass[middle] < value)
		{
			left = middle + 1;

		}
		else
		{
			if (mass[middle] > value)
			{
				right = middle - 1;
			}
			else
			{
				index = true;
				break;
			}
		}
	}
	return index;
}

void printMass(int mass[], int low, int high)
{
	for (int i = low; i < high; ++i)
	{
		printf("mass[%u] = %u\n", i, mass[i]);
	}
	printf("\n");
}

void test()
{
	int massTest[12]{ 4, 6, 13, 1, 9, 5, 1, 4, 2, 7, 9, 3 };
	quickSort(massTest, 0, 11);
	if ((massTest[3] == 3) && (massTest[8] >= massTest[3]) && (massTest[2] < massTest[3]) && (binarySearch(massTest, 12, 1)) && (!binarySearch(massTest, 12, 12)))
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
	int k = 0;

	printf("Enter the number of elements in your array n = ");
	scanf("%u", &n);

	printf("Enter the number of elements k = ");
	scanf("%u", &k);

	int *mass = new int[n];

	for (int i = 0; i < n; ++i) // заполняем массив случайными числами
	{
		mass[i] = rand() % 1000000000;
		printf("mass[%u] = %u\n", i, mass[i]);
	}
	printf("\n");

	quickSort(mass, 0, n - 1);

	printMass(mass, 0, n);

	for (int i = 0; i < k; ++i)
	{
		int element = rand() % 1000000000;
		if (n == 0)
		{
			printf("The array is empty\n");
			break;
		}
		else
		{
			if (binarySearch(mass, n, element))
			{
				printf("Element %u is contained in the array\n", element);
			}
			else
			{
				printf("Element %u isn't contained in the array\n", element);
			}
		}
	}

	delete[] mass;
	return 0;
}