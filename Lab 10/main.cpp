#include <iostream>
#include <array>
#include <Windows.h>
#include <conio.h>

using  funcPtr = double(*)(double, double);

double average(double x, double y);
double sumOfSquare(double x, double y);
double sumOfTrigonom(double x, double y);
double yDivideX(double x, double y);
void menu(std::array<funcPtr, 4>& functions);

int main()
{
	setlocale(0, "ru");

	std::array<funcPtr, 4> functions = {average, sumOfSquare, sumOfTrigonom, yDivideX};

	menu(functions);

	return 0;
}

double average(double x, double y)
{
	return (x + y) / 2;
}

double sumOfSquare(double x, double y)
{
	return x * x + y * y;
}

double sumOfTrigonom(double x, double y)
{
	return sin(x) + sin(y);
}

double yDivideX(double x, double y)
{
	return y / x;
}

void menu(std::array<funcPtr, 4> &functions)
{
	int choise;
	double arg1;
	double arg2;

	do
	{
		std::cout
			<< "1. ������� ��������.\n"
			<< "2. ����� ��������� �����.\n"
			<< "3. ����� ������� �����.\n"
			<< "4. ������ ������ �� ������.\n"
			<< "5. �����.\n\n";
		std::cout << "������� ����� �������, ������� ������ ������������: ";
		std::cin >> choise;
		if (choise == 5)
			return ;
		std::cout << "\n������� ������ �����: ";
		std::cin >> arg1;
		std::cout << "������� ������ �����: ";
		std::cin >> arg2;

		switch (choise)
		{
		case(1): std::cout << "������� �������� ����� ����� �������: " << functions.at(0)(arg1, arg2); break;
		case(2): std::cout << "����� ��������� �����: " << functions.at(1)(arg1, arg2); break;
		case(3): std::cout << "����� ������� �����: " << functions.at(2)(arg1, arg2); break;
		case(4): std::cout << "�������: " << functions.at(3)(arg1, arg2); break;
		default: std::cout << "�������� ����� �� ������!"; break;
		}
		std::cout << "\n\n\n������� ����� ������� ��� �����������...";
		_getch();
		system("cls");
	} while (true);
}