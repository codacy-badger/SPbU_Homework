#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "stack.h"
#include "list.h"
using namespace std;

bool **createGraph(const int size)
{
	bool **graph = new bool*[size];
	for (int i = 0; i < size; i++)
	{
		graph[i] = new bool[size];
		for (int j = 0; j < size; j++)
		{
			graph[i][j] = false;
		}
	}
	return graph;
}

void deleteGraph(bool **graph, const int size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] graph[i];
	}
	delete[] graph;
}

bool exists(vector<int> vertex, int value)
{
	for (int i = 0; i < vertex.size(); i++)
	{
		if (vertex[i] == value)
		{
			return true;
		}
	}

	return false;
}

vector<int> vertexes(bool **graph, int size)
{
	vector<int> reachable(size);
	for (int l = 0; l < size; l++)
	{
		reachable[l] = -1;
	}
	int sizeVector = 0;
	for (int i = 0; i < size; i++)
	{
		vector<int> temp(size); // reachable vertexes
		Stack *stackOfNotVisited = createStack();
		List *listOfVisited = createList();
		int counter = 0;

		listOfVisited = addIntoList(listOfVisited, i);

		for (int j = 0; j < size; j++)
		{
			if (graph[i][j] == true)
			{
				push(stackOfNotVisited, j);
				temp[counter] = j;
				counter++;
			}
		}

		while (!isEmptyStack(stackOfNotVisited))
		{
			int current = pop(stackOfNotVisited);
			if (!existsList(listOfVisited, current))
			{
				for (int k = 0; k < size; k++)
				{
					if (graph[current][k] == true)
					{
						if (!existsStack(stackOfNotVisited, k))
						{
							push(stackOfNotVisited, k);
						}
						if (!exists(temp, k))
						{
							temp[counter] = k;
							counter++;
						}
					}
				}
			}
			listOfVisited = addIntoList(listOfVisited, current);
		}

		bool flag = true;
		for (int g = 0; g < size; g++)
		{
			if (!exists(temp, g) && g != i)
			{
				flag = false;
			}
		}
		if (flag)
		{
			reachable[sizeVector] = i;
			sizeVector++;
		}
		deleteList(listOfVisited);
		deleteStack(stackOfNotVisited);
	}
	return reachable;
}

// ������ ��������� ������� (������ �������� ������� ��� ������ ������)
// ���������� ��������� ������� � �������� �� �� ��������������� ������ ������������ ������
// �������� � ���� ��� �������, ������� �� ���������
// ������������ ���� �� ������� ����������� ����� � ������ ����� ��������� :
//   ������� �� ����� ��������� �������
//   ��������� �� ���������������� ������ �������������� ���� �������
//   ���� ������� ��� ����������, �� ������� �� ����� ��������� �������
//   ���� ������� ��� �� ����������, �� ���������� �� � ��������� � ������ ������������ ������
//   ����������� ���� ������ ������� � ��� ������ � ��������� � ���� ��� ��� �� ������������ �������