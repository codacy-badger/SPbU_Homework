#include "pch.h"
#include <stdio.h>
#include <cmath>

int incq(int a, int b) // incomplete  quotient с англ. неполное частное
{
	int result = 0;
	while (a - b >= 0)
	{
		a = a - b;
		result++;
	}
	return result;
}

int main()
{
	int a, b;
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	int result = incq(abs(a), abs(b));
	if (a <= 0)
		if (b > 0)
		{
			result = -result - 1;
		}
		else
		{
			result++;
		}
	else
		if (b < 0)
		{
			result = -result;
		}
	printf("Result is %d", result);
	return 0;
}