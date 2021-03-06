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

	int input = 0;
	int amount = 0;

	FILE *file = fopen("4.2.txt", "r");
	if (!file) 
	{
		printf("File not found!");
		return 1;
	}
	else
	{
		while (!feof(file))
		{
			fscanf(file, "%d ", &input);
			++amount;
		}
	}

	int *mass = new int[amount];

	fseek(file, 0, SEEK_SET);
	for (int i = 0; i < amount; ++i)
	{
		fscanf(file, "%d ", &mass[i]);
		printf("mass[%u] = %u\n", i, mass[i]);
	}
	fclose(file);

	printf("\n");

	quickSort(mass, 0, amount - 1);

	printMass(mass, 0, amount);

	printf("The most frequent element in array is %u", theMostFrequentElement(mass, amount));

	delete[] mass;
	return 0;
}