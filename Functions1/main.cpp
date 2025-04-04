#include<iostream>
using namespace std;

// параметрыпо умолчанию ТОЛЬКО в прототипе
int Sum(int a=0, int b=0, int c=0 );                    // Прототип функции
int Difference(int a, int b); // разность
int Product(int a, int b);    // произведение
double Quotient(int a, int b);// частное


void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello Functions" << endl;
	int a = 2;
	int b = 3;
	int c = Sum(a, b, 11);                             // использование функции (вызов функции)
	cout << a << "+" << b << "=" << c << endl;

	                                //передаваемые параметры!!! в вызове функции=принимаемым
	cout << a << "-" << b << "=" << Difference(a, b) << endl;
	cout << a << "*" << b << "=" << Product(a, b) << endl;
	cout << a << "/" << b << "=" << Quotient(a, b) << endl;
	cout << 4 << "+" << 5 << "=" << Sum(4, 5) << endl;
	cout << Sum() << endl; //отработала так как три параметра с 0!
}
             //(принимаемые параметры)
	int Sum(int a, int b, int c)                       // реализация функции(она же объявляет функцию - без прототипа)
	{
		int res = a + b + c; return res;//тело функции
	}
	int Difference(int a, int b) 
	{
		return a - b;
	}
	int Product(int a, int b)
	{
		return a * b;
	}
	double Quotient(int a, int b)
	{
		return (double)a / b;
	}
