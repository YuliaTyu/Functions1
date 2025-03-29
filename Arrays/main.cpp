#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void Sort(int arr[], const int n);
int Sum(int arr[], const int n);
double Avg(int arr[], const int n);
int Min(int arr[], const int n);
int Max(int arr[], const int n);
void  ShiftLeft(int arr[], const int n, const int shifts);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
	int arr[n];


	FillRand(arr, n);
	Print(arr, n);
	Sort(arr, n);
	Print(arr, n);

	cout << "����� ��������� �������" << Sum(arr, n) << endl;
	cout << "��������������������" << Avg(arr, n) << endl;
	cout << "����������� �������� � �������" << Min(arr, n) << endl;
	cout << "������������ �������� � �������" << Max(arr, n) << endl;


	const int SIZE = 8;
	int brr[SIZE];
	FillRand(brr, SIZE);
	Print(brr, SIZE);
	Sort(brr, SIZE);
	Print(brr, SIZE);
	cout << "����� ��������� �������" << Sum(brr, SIZE) << endl;
	cout << "��������������������" << Avg(brr, SIZE) << endl;
	cout << "����������� �������� � �������" << Min(brr, SIZE) << endl;
	cout << "������������ �������� � �������" << Max(brr, SIZE) << endl;
	int shifts;
	cout << "������� ���������� ������"; cin >> shifts;
	ShiftLeft(brr, SIZE, shifts);
	Print(brr, SIZE);
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Sort(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
}
int Sum(int arr[], const int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}
double Avg(int arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
int Min(int arr[], const int n)
{
	int min = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min)min = arr[i];
	}
	return min;
}
int Max(int arr[], const int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
}
void  ShiftLeft(int arr[], const int n, const int shifts)
{
	for (int i = 0; i < shifts; i++)
	{
		int buffer = arr[0];
		for (int i = 1; i < n; i++)
		{
			arr[i - 1] = arr[i];
		}
		arr[n - 1] = buffer;
	}
}