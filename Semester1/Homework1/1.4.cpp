#include "pch.h" 
#include <stdio.h> 

int main()
{
	int mass[28] = { 0 };
	int sum = 0;
	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int h = 0; h <= 9; h++)
			{
				sum = i + j + h;
				mass[sum]++;
			}
		}
	}
	sum = 0;
	for (int i = 0; i <= 27; i++)
	{
		sum = sum + mass[i] * mass[i];
		printf("For sum = %u there are %u variations\n", i, mass[i] * mass[i]);
	}
	printf("Total amount of variations is %u", sum);
	return 0;
}