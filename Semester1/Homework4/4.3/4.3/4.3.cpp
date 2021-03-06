#include "pch.h"
#include <stdio.h>
#include <iostream> // library iostream is used only for setlocale, the rest of this code is written using stdio.h

struct Records
{
	char name[50] = "";
	char phoneNumber[20] = "";
};

void printCommands()
{
	printf("0 - выйти\n");
	printf("1 - добавить запись (имя и телефон)\n");
	printf("2 - распечатать все имеющиеся записи\n");
	printf("3 - найти телефон по имени\n");
	printf("4 - найти имя по телефону\n");
	printf("5 - сохранить текущие данные в файл\n");
}

void case2(Records record[], int numberOfRecords)
{
	for (int i = 0; i < numberOfRecords; ++i)
	{
		printf("%u. Имя: %s; телефон: %s\n", i + 1, record[i].name, record[i].phoneNumber);
	}
	printf("\n");
}

int case3(Records record[], int numberOfRecords, char const neededName[])
{
	int numberOfNeeded = 0;
	
	while ((numberOfNeeded <= numberOfRecords) && (strcmp(neededName, record[numberOfNeeded].name) != 0))
	{
		++numberOfNeeded;
	}
	if (numberOfNeeded > numberOfRecords)
	{
		return -1;
	}
	else
	{
		return numberOfNeeded;
	}
}

int case4(Records record[], int numberOfRecords, char const neededPhoneNumber[])
{
	int numberOfNeeded = 0;
	
	while ((numberOfNeeded <= numberOfRecords) && (strcmp(neededPhoneNumber, record[numberOfNeeded].phoneNumber) != 0))
	{
		++numberOfNeeded;
	}
	if (numberOfNeeded > numberOfRecords)
	{
		return -1;
	}
	else
	{
		return numberOfNeeded;
	}
}

void case5(Records record[], int numberOfRecords)
{
	FILE *file = fopen("4.3.txt", "w");
	for (int i = 0; i < numberOfRecords - 1; ++i)
	{
		fprintf(file, "%s %s\n", record[i].name, record[i].phoneNumber);

	}
	fprintf(file, "%s %s", record[numberOfRecords - 1].name, record[numberOfRecords - 1].phoneNumber);
	fclose(file);
	printf("Данные сохранены.\n");
	printf("\n");
}


void test()
{
	Records test[3]{ { "Man", "10101" }, { "Woman", "22222" }, { "Child", "33344" } };
	if ((case3(test, 3, "Woman") == 1) && (case4(test, 3, "33344") == 2) && (case3(test, 3, "Child") == 2) && (case4(test, 3, "10101") == 0))
	{
		printf("Test passed.\n");
		printf("\n");
	}
	else
	{
		printf("Test failed.\n");
		printf("\n");
	}
}

int main()
{
	test();
	int numberOfRecords = 0;
	Records record[100];

	setlocale(LC_ALL, "Russian");

	FILE *file = fopen("4.3.txt", "a+");
	
	char *bufferName = new char[50];
	char *bufferPhoneNumber = new char[20];

	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	if (size != 0)
	{
		fseek(file, 0, SEEK_SET);
		for (int i = 0; (!feof(file)) && (i < 100); ++i)
		{
			fscanf(file, "%s %s", bufferName, bufferPhoneNumber);
			strcpy(record[i].name, bufferName);
			strcpy(record[i].phoneNumber, bufferPhoneNumber);
			++numberOfRecords;
		}
	}
	fclose(file);

	delete[] bufferName;
	delete[] bufferPhoneNumber;
	
	int input = 0;
	printCommands();
	scanf("%u", &input);
	while (input != 0)
	{
		switch (input)
		{
		case 1:
		{
			char newName[50]{ 0 };
			char newPhoneNumber[20]{ 0 };
			printf("Введите имя ");
			scanf("%s", record[numberOfRecords].name);
			printf("Введите номер телефона ");
			scanf("%s", record[numberOfRecords].phoneNumber);
			++numberOfRecords;
			printf("\n");
			break;
		}
		case 2:
		{
			case2(record, numberOfRecords);
			break;
		}
		case 3:
		{
			char const neededName[50] = "";
			printf("Введите имя ");
			scanf("%s", &neededName);
			if (case3(record, numberOfRecords, neededName) == -1)
			{
				printf("Запись не найдена\n");
				printf("\n");
			}
			else
			{
				printf("Номер телефона: %s\n", record[case3(record, numberOfRecords, neededName)].phoneNumber);
				printf("\n");
			}
			break;
		}
		case 4:
		{
			char const neededPhoneNumber[20]{ 0 };
			printf("Введите номер телефона ");
			scanf("%s", &neededPhoneNumber);
			if (case4(record, numberOfRecords, neededPhoneNumber) == -1)
			{
				printf("Запись не найдена\n");
				printf("\n");
			}
			else
			{
				printf("Имя: %s\n", record[case4(record, numberOfRecords, neededPhoneNumber)].name);
				printf("\n");
			}
			
			break;
		}
		case 5:
		{
			case5(record, numberOfRecords);
			break;
		}
		default:
		{
			printf("Введена неверная команда.\n");
			printf("\n");
			break;
		}
		}
		printCommands();
		scanf("%u", &input);
	}
	
	return 0;
}

//Написать программу - телефонный справочник.Она должна уметь хранить имена и номера телефонов, в интерактивном режиме осуществлять следующие операции :
//0 - выйти
//1 - добавить запись(имя и телефон)
//2 - распечатать все имеющиеся записи
//3 - найти телефон по имени
//4 - найти имя по телефону
//5 - сохранить текущие данные в файл
//При запуске программа должна читать данные из файла, если файла нет - начинать с пустой базы номеров.Размер базы ограничен сотней записей.