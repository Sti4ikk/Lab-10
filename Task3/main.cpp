#include <iostream>
#include <array>
#include <Windows.h>
#include <conio.h>

using funcPtr = void(*)();

void menu();
void numOfSymbols();
void startAndEnd();

std::array<funcPtr, 2> functions{ numOfSymbols, startAndEnd };


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);



	menu();

	return 0;
}

void menu()
{
	int choise;
	do
	{
		std::cout
			<< "1. ���-�� ��������.\n"
			<< "2. ��������� � �������� �������.\n\n"
			<< "�������� �����: ";

		std::cin >> choise;
		system("cls");

		switch (choise)
		{
		case(1): functions.at(0)(); break;
		case(2):functions.at(1)(); break;
		default: std::cout << "�������� ����� �� ������!"; break;
		}

	} while (choise != 1 or choise != 2);
}

void numOfSymbols()
{
	int amount;
	std::string str;
	std::cout << "������� ������ ��� �����: ";
	std::cin >> str;

	std::cout << "������� ���-�� ��������: ";
	std::cin >> amount;

	for (int i = 0; i < amount; i++)
	{
		std::cout << str;
	}

	std::cout << "\n\n������� ����� ������� ��� �����������..";
	_getch();
	system("cls");
}

void startAndEnd()
{
	std::string str;
	std::cout << "������� ������ ��� �����: ";
	std::cin >> str;

	int start;
	int end;
	std::cout << "������� ��������� �������: ";
	std::cin >> start;
	std::cout << "������� �������� �������: ";
	std::cin >> end;

	for (int i = 0; i < end; i++)
	{
		if ((i + 1) < start)
			std::cout << " ";
		else
			std::cout << str;
	}

	std::cout << "\n\n������� ����� ������� ��� �����������..";
	_getch();
	system("cls");
}