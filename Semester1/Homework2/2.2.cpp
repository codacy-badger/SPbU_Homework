#include "pch.h"
#include <stdio.h>

int exponentiationHard(int base, int exponent)
{
	if (exponent == 0)
	{
		return 1;
	}
	else
	{
		int help = base;
		for (int i = 1; i < exponent; ++i)
		{
			base = base * help;
		}
		return base;
	}
}

int exponentiationEasy(int base, int exponent)
{
	if (exponent == 0)
	{
		return 1;
	}
	else
	{
		if (exponent % 2 == 0)
		{
			int help = exponentiationEasy(base, exponent / 2);
			return help * help;
		}
		else
		{
			return exponentiationEasy(base, exponent - 1) * base;
		}
	}
}

void test()
{
	if ((exponentiationHard(2, 7) == 128) && (exponentiationHard(7, 2) == 49) && (exponentiationHard(6, 3) == 216) && 
		(exponentiationEasy(5, 3) == 125) && (exponentiationEasy(3, 6) == 729) && (exponentiationEasy(11, 3) == 1331))
	{
		printf("Tests passed\n");
	}
	else
	{
		printf("Tests failed\n");
	}
}

int main()
{
	int base = 0;
	int exponent = 0;
	test();
	printf("Enter the base ");
	scanf("%u", &base);
	printf("Enter the exponent ");
	scanf("%u", &exponent);
	printf("The result of hard exponentiation is %u", exponentiationHard(base, exponent));
	printf("\n");
	printf("The result of easy exponentiation is %u", exponentiationEasy(base, exponent));
	return 0;
}