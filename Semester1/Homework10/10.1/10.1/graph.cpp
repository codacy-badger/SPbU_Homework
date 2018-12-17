#include "pch.h"
#include <iostream>
#include "graph.h"
using namespace std;

int **createGraph(const int size)
{
	int **graph = new int*[size]; // ������� ��������� ������������ ������
	for (int i = 0; i < size; i++)
	{
		graph[i] = new int[size];
	}
	for (int i = 0; i < size; i++) // �������� ������
	{
		for (int j = 0; j < size; j++)
		{
			graph[i][j] = 0;
		}
	}
	return graph;
}

void deleteGraph(int **graph, const int size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] graph[i];
	}
	delete[] graph;
}

int *createArray(const int size)
{
	int *array = new int[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = -1;
	}
	return array;
}

void citiesRoadsCountries(int **graph, int amountOfCities, int *cityToCountry, int amountOfCapitals, int *capitals)
{
	int freeCities = amountOfCities - amountOfCapitals;
	while (freeCities > 0)
	{
		for (int i = 0; i < amountOfCapitals; i++)
		{
			int minimumLength = 10000000;
			int numberOfClosestCity = -1;
			for (int j = 0; j < amountOfCities; j++)
			{
				if ((cityToCountry[j] == -1) && (graph[j][capitals[i]] != 0) && (graph[j][capitals[i]] < minimumLength)) // ���� ��������� ��������� ��������� �� �������� �����
				{
					minimumLength = graph[j][amountOfCapitals];
					numberOfClosestCity = j;
				}
			}
			for (int k = 0; k < amountOfCities; k++)
			{
				if ((cityToCountry[k] == capitals[i]) && (capitals[i] != k)) // ���� ����� ����������� ������� ������ � �� �������� ��������
				{
					for (int p = 0; p < amountOfCities; ++p)
					{
						if ((cityToCountry[p] == -1) && (graph[k][p] != 0) && (graph[k][p] < minimumLength)) // �� ���� ��������� ��������� ��������� � ����������� �����
						{
							minimumLength = graph[k][p];
							numberOfClosestCity = p;
						}
					}
				}
			}
			if (numberOfClosestCity != -1)
			{
				cityToCountry[numberOfClosestCity] = capitals[i];
				freeCities--;
			}
			if (freeCities == 0)
			{
				break;
			}
		}
	}
}

void printCountriesCities(int *cityToCountry, int amountOfCities, int *capitals, int amountOfCapitals)
{
	for (int i = 0; i < amountOfCapitals; i++)
	{
		cout << "����� ����������� " << i << endl;
		cout << "������ ";
		for (int k = 0; k < amountOfCities; k++)
		{
			if (cityToCountry[k] == capitals[i])
			{
				cout << k << " ";
			}
		}
		cout << "\n";
	}
}

// ��� ���� ��������� ������ � ������, ������ ����������: � ����� �� �������, ��� ������ ������ ������� ��������� � ������ ����� � ��������� ���. 
// ���� ������ ������ ��������� (��� �������� ������ ���������), ���������� ������, ���� �� ����� ������ ������ ��������, �� ��.
// ��� ������ ��������� �����-- - ������ ������, ��� ������, ���� ������ ���������� �����, �� ����� � ������������ ������� �������� �������, ��� � ��������� ��������


// ���� ��������� ������� � ������, ����������� ��� ������. ��� ������ ������ ������ � �����. 
// ������ � ������������ ������ ����� ������������� �� ������ ���������: 
// �������� k ������ ������� �����������, ����� �� ������� ������� ����������� ����������� ��������� ��������� �����, 
// ��������������� ��������� ������� � �����-���� �������, ��� ������������� ����������� (�������� ��� �����-���� �������, ����������� �� ����� �� ���������� �����). 
// ������� ������������ �� ��� ���, ���� ��� ������ �� ����� ������������. ���� ����� �������. 
// �� ������� �����: n � ����� ������� � m � ����� �����. ����� ������� ���� ������ � �������: i j len, i � j � ������ �������, len � ����� ������. 
// ����� ������ ����� k � ����� ������, ����� � k ����� � ������ ������. ���� ������� �� ������� ������ ���������� � ������ �������, ������������� ������������.