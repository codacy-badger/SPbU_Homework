#include "pch.h"
#include "binary.h"
#include <stdio.h>
#include "locale.h"
#include "test.h"

int main()
{
	test();

	setlocale(LC_ALL, "Russian");

	bool array1[32]{ 0 };
	int number1 = 0;
	bool array2[32]{ 0 };
	int number2 = 0;
	bool sum[32]{ 0 };

	printf("Введите первое число\n");
	scanf("%d", &number1);
	printf("Введите второе число\n");
	scanf("%d", &number2);

	intoTwosComplement(number1, array1);
	printBinary(array1);
	intoTwosComplement(number2, array2);
	printBinary(array2);

	sumOfTwosComplements(array1, array2, sum);
	printBinary(sum);

	printf("Сумма равна %d", fromTwosComplements(sum));

	return 0;
}

// Ввести два числа, перевести в двоичное представление в дополнительном коде и напечатать, сложить в столбик в двоичном представлении, 
// вывести сумму, перевести в десятичное, вывести сумму в десятичном виде. 
// Все сообщения писать по-русски (рекомендуется использовать функцию setlocale, чтобы сообщения выводились по-русски и под Windows тоже).