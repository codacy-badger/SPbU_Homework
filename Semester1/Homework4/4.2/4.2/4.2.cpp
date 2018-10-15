#include "pch.h"
#include "quickSort.h"
#include "theMostFrequentElement.h"
#include "test.h"
#include <stdio.h>
#include <cstdlib>

void printMass(int mass[], int low, int high)
{
	for (int i = low; i < high; ++i)
	{
		printf("mass[%u] = %u\n", i, mass[i]);
	}
	printf("\n");
}

int main()
{
	test();

	int n = 0;

	FILE *file = fopen("4.2.txt", "r");
	if (!file) 
	{
		printf("File not found!");
		return 1;
	}
	else
	{
		fscanf(file, "%u", &n);
	}
	fclose(file);

	int *mass = new int[n];

	for (int i = 0; i < n; ++i) // заполняем массив случайными числами
	{
		mass[i] = rand() % 10;
		printf("mass[%u] = %u\n", i, mass[i]);
	}
	printf("\n");

	quickSort(mass, 0, n - 1);

	printMass(mass, 0, n);

	printf("The most frequent element in array is %u", theMostFrequentElement(mass, n));

	delete[] mass;
	return 0;
}