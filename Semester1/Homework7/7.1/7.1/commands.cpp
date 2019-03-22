#include "pch.h"
#include "commands.h"
#include "binaryTree.h"
#include <iostream>
using namespace std;

void printCommands()
{
	cout << "0 � �����" << endl;
	cout << "1 � �������� �������� �� ���������" << endl;
	cout << "2 � ������� �������� �� ���������" << endl;
	cout << "3 � ���������, ����������� �� �������� ���������" << endl;
	cout << "4 � ����������� ������� �������� ��������� � ������������ �������" << endl;
	cout << "5 � ����������� ������� �������� ��������� � ��������� �������" << endl;
}

void command1(BinaryTree *tree)
{
	int data = 0;
	cout << "������� ����������� ��������" << endl;
	cin >> data;
	if (!add(tree, data))
	{
		cout << "����������� �������� ��� ���������� �� ���������." << endl;
	}
	cout << "\n";
}

void command2(BinaryTree *tree)
{
	int data = 0;
	cout << "������� ��������� ��������" << endl;
	cin >> data;
	if (!remove(tree, data))
	{
		cout << "��������� �������� �� ���������� �� ���������." << endl;
	}
	cout << "\n";
}

void command3(BinaryTree *tree)
{
	int data = 0;
	cout << "������� ����������� ��������" << endl;
	cin >> data;
	if (exists(tree, data))
	{
		cout << "�������� ���������� �� ���������." << endl;
	}
	else
	{
		cout << "�������� �� ���������� �� ���������." << endl;
	}
	cout << "\n";
}

void command4(BinaryTree *tree)
{
	printBinaryTreeAscendingOrder(tree);
	cout << "\n";
	cout << "\n";
}

void command5(BinaryTree *tree)
{
	printBinaryTreeDescendingOrder(tree);
	cout << "\n";
	cout << "\n";
}

void commands()
{
	BinaryTree *tree = createTree();

	int input = 0;
	printCommands();
	cin >> input;
	while (input != 0)
	{
		switch (input)
		{
		case 1:
		{
			command1(tree);
			break;
		}
		case 2:
		{
			command2(tree);
			break;
		}
		case 3:
		{
			command3(tree);
			break;
		}
		case 4:
		{
			command4(tree);
			break;
		}
		case 5:
		{
			command5(tree);
			break;
		}
		default:
		{
			cout << "������� �������� �������.\n" << endl;
			break;
		}
		};
		printCommands();
		cin >> input;
	}

	deleteBinaryTree(tree);
}