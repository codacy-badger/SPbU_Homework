#include "pch.h"
#include "commands.h"
#include <iostream>
using namespace std;

//Юна супер и Вова тоже скоро я стану частью вашей семьи

int main()
{
	setlocale(LC_ALL, "Russian");

	element *head = new element{ 0, nullptr };
	List *list = new List{ head, 1 };

	int input = 0;
	printCommands();
	cin >> input;
	while (input != 0)
	{
		switch (input)
		{
		case 1:
		{
			int inputValue = 0;
			cout << "Введите значение " << endl;
			cin >> inputValue;
			addValueIntoList(list, inputValue);
			cout << "\n";
			break;
		}
		case 2:
		{
			if (list->isEmpty == 1)
			{
				cout << "Список пуст.\n" << endl;
				break;
			}
			else
			{
				int inputValue = 0;
				cout << "Введите значение " << endl;
				cin >> inputValue;
				deleteValueFromList(list, inputValue);
				cout << "\n";
				break;
			}
		}
		case 3:
		{
			printList(list);
			break;
		}
		default:
		{
			cout << "Введена неверная команда.\n" << endl;
			break;
		}
		};
		printCommands();
		cin >> input;
	}
	delete head;
	delete list;
	return 0;    
}

// Написать программу, которая в диалоговом режиме позволяет осуществлять следующие операции:
// 0 – выйти
// 1 – добавить значение в сортированный список
// 2 – удалить значение из списка
// 3 – распечатать список
// Все операции должны сохранять сортированность.Начинаем с пустого списка.

