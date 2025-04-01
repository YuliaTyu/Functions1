#include<iostream>
using namespace std;

#define delimiter "\n------------------------------------\n"

const int ROWS = 4;
const int COLS = 5;

void FillRand(int arr[], const int n); //заполнение массива случайными числами
void FillRand(double arr[], const int n);
void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS);

void Print(int arr[], const int n);
void Print(double arr[], const int n);
void Print(int arr[4][5], const int ROWS, const int COLS);

void Sort(int arr[], const int n);
void Sort(double arr[], const int n);

int Sum(int arr[], const int n);
double Sum(double arr[], const int n);
int Sum(int arr[ROWS][COLS], const int ROWS, const int COLS);

double Avg(int arr[], const int n);
double Avg(double arr[], const int n);

int Min(int arr[], const int n);
double Min(double arr[], const int n);
int Min(int arr[ROWS][COLS], const int ROWS, const int COLS);

int Max(int arr[], const int n);
double Max(double arr[], const int n);

void  ShiftLeft(int arr[], const int n, const int shifts);
void  ShiftLeft(double arr[], const int n, const int shifts);



void main()
{
	setlocale(LC_ALL, "");

	const int n = 5;
	int arr[n];

	FillRand(arr, n);
	Print(arr, n);
	Sort(arr, n);
	Print(arr, n);

	cout << "Сумма элементов массива: " << Sum(arr, n) << endl;
	cout << "Среднеарифметическое: " << Avg(arr, n) << endl;
	cout << "Минимальное значение в массиве: " << Min(arr, n) << endl;
	cout << "Максимальное значение в массиве: " << Max(arr, n) << endl;


	const int SIZE = 8;
	double brr[SIZE];

	FillRand(brr, SIZE);
	Print(brr, SIZE);
	Sort(brr, SIZE);
	Print(brr, SIZE);

	cout << "Сумма элементов массива: " << Sum(brr, SIZE) << endl;
	cout << "Среднеарифметическое: " << Avg(brr, SIZE) << endl;
	cout << "Минимальное значение в массиве: " << Min(brr, SIZE) << endl;
	cout << "Максимальное значение в массиве: " << Max(brr, SIZE) << endl;
	int shifts;
	cout << "Введите количество сдигов: "; cin >> shifts;
	ShiftLeft(brr, SIZE, shifts);	
	Print(brr, SIZE);
	
	cout << delimiter << endl;

	
	int i_arr_2[ROWS][COLS] =
	{
		{3,5,8},
		{13,21,34},
		{55,89,144},
	};
	

	FillRand(i_arr_2, ROWS, COLS);
	Print(i_arr_2, ROWS, COLS);
	cout << "Сумма двумер массива: ";	
	Sum(i_arr_2, ROWS, COLS); cout << endl;
	cout << "Минимальное значение двумер массива: "; 
	Min(i_arr_2, ROWS, COLS); cout << endl;

	
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10000;
		arr[i] /= 100;
	}
}
void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand();
		}
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
void Print(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int arr[4][5], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
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
void Sort(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				double buffer = arr[i];
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
double Sum(double arr[], const int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}
int Sum(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int sum = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			sum += arr[ROWS][COLS];
		}
		cout << sum;
	}
	return sum;  // я не знаю что он считает (((((

}


double Avg(int arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
double Avg(double arr[], const int n)
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
double Min(double arr[], const int n)
{
	double min = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min)min = arr[i];
	}
	return min;
}
int Min(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int min = arr[ROWS][COLS];
		for(int i = 1; i < ROWS; i++)
		{
			for (int j = 1; j < COLS; j++)
			{
				if (arr[ROWS][COLS] < min)min = arr[ROWS][COLS];
			}

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
double Max(double arr[], const int n)
{
	double max = arr[0];
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
void  ShiftLeft(double arr[], const int n, const int shifts)
{
	for (int i = 0; i < shifts; i++)
	{
		double buffer = arr[0];
		for (int i = 1; i < n; i++)
		{
			arr[i - 1] = arr[i];
		}
		arr[n - 1] = buffer;
	}
}

