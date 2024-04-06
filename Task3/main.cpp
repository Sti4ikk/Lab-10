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
			<< "1. Кол-во символов.\n"
			<< "2. Начальная и конечная позиция.\n\n"
			<< "Выберите режим: ";

		std::cin >> choise;
		system("cls");

		switch (choise)
		{
		case(1): functions.at(0)(); break;
		case(2):functions.at(1)(); break;
		default: std::cout << "Выберите цифру из списка!"; break;
		}

	} while (choise != 1 or choise != 2);
}

void numOfSymbols()
{
	int amount;
	std::string str;
	std::cout << "Введите символ или слово: ";
	std::cin >> str;

	std::cout << "Введите кол-во символов: ";
	std::cin >> amount;

	for (int i = 0; i < amount; i++)
	{
		std::cout << str;
	}

	std::cout << "\n\nНажмите любую клавише для продолжения..";
	_getch();
	system("cls");
}

void startAndEnd()
{
	std::string str;
	std::cout << "Введите символ или слово: ";
	std::cin >> str;

	int start;
	int end;
	std::cout << "Введите начальную позицию: ";
	std::cin >> start;
	std::cout << "Введите конечную позицию: ";
	std::cin >> end;

	for (int i = 0; i < end; i++)
	{
		if ((i + 1) < start)
			std::cout << " ";
		else
			std::cout << str;
	}

	std::cout << "\n\nНажмите любую клавише для продолжения..";
	_getch();
	system("cls");
}