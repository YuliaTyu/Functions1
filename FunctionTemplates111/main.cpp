#include<iostream>
using namespace std;


#include"PrintT.h" //Шаблон, ведь, не компилируется, а инстанцируется по фактическому значению параметров!!!!!!!!!!!

#define delimiter "\n------------------------------------\n"

const int ROWS = 4;
const int COLS = 10;

void FillRand(int arr[], const int n); //заполнение массива случайными числами
void FillRand(double arr[], const int n);
void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS, int minRand = 0, int maxRand = 100);
void FillRand(double arr[ROWS][COLS], const int ROWS, const int COLS);



template<typename T>
void Print(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>
void Sort(T arr[], const int n);     //сортировка массива
template<typename T>
void Sort(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>
T Sum(T arr[], const int n);        //сумма массива
template<typename T>
T Sum(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>
double Avg(T arr[], const int n);     //среднеарифметическое
template<typename T>
double Avg(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>
T Min(T arr[], const int n);
template<typename T>
T Min(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>
T Max(T arr[], const int n);
template<typename T>
T Max(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>
void  ShiftLeft(T arr[], const int n, const int shifts); // сдвиг влево
template<typename T>
void  ShiftRight(T arr[], const int n, const int shifts);


void ShiftLeft(int arr[ROWS][COLS], const int ROWS, const int COLS, int shifts);


void main()
{
	setlocale(LC_ALL, "");

	const int n = 10;
	double arr[n] = { 0,1,2,3,4,5,6,7,8,9 };

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
	Print(brr, SIZE);
	int shifts;
	cout << "Введите количество сдигов: "; cin >> shifts;
	ShiftLeft(brr, SIZE, shifts);
	Print(brr, SIZE);

	cout << "Введите количество сдвигов: "; cin >> shifts;
	ShiftRight(brr, SIZE, shifts);

	cout << delimiter << endl;


	int i_arr_2[ROWS][COLS] =              //объявление двумерного массива
	{
		{3,5,8},
		{13,21,34},
		{55,89,144},
	};


	FillRand(i_arr_2, ROWS, COLS);

	cout << "Сумма двумер массива: " << Sum(i_arr_2, ROWS, COLS) << endl;
	cout << "Среднеарифметическое: " << Avg(i_arr_2, ROWS, COLS) << endl;
	cout << "Минимальное значение двумер массива: " << Min(i_arr_2, ROWS, COLS) << endl;
	cout << "Максимальное значение двумер массива" << Max(i_arr_2, ROWS, COLS) << endl;
	Sort(i_arr_2, ROWS, COLS);
	Print(i_arr_2, ROWS, COLS);
	cout << "Введите количество сдвигов: "; cin >> shifts;
	ShiftLeft(i_arr_2, ROWS, COLS, shifts);
	Print(i_arr_2, ROWS, COLS);



}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;            //функция rand()возвращает случайое число в диапазоне от0 до 32767
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
void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS, int minRand, int maxRand)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}
}
void FillRand(double arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand();
		}
	}
}




template<typename T>
void Print(T arr[ROWS][COLS], const int ROWS, const int COLS)
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



template<typename T>
void Sort(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				T buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
}
template<typename T>
void Sort(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int iter = 0;
	int exch = 0;
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
		{
			for (int k = i; k < ROWS; k++)
			{
				for (int l = k == i ? j + 1 : 0; l < COLS; l++)//int l = k > i ? 0 : j + 1
				{
					iter++;
					if (arr[k][l] < arr[i][j])
					{
						T buffer = arr[i][j];
						arr[i][j] = arr[k][l];
						arr[k][l] = buffer;
						exch++;
					}
				}
			}
		}
	cout << "Колич итераций" << iter << endl;
	cout << "Колич обменов" << exch << endl;
}


template<typename T>
T Sum(T arr[], const int n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}
template<typename T>
T Sum(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	T sum = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;

}

template<typename T>
double Avg(T arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
template<typename T>
double Avg(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	return (double)Sum(arr, ROWS, COLS) / ROWS / COLS;
}

template<typename T>
T Min(T arr[], const int n)
{
	int min = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min)min = arr[i];
	}
	return min;
}
template<typename T>
T Min(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	T min = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] < min)min = arr[i][j];
		}

	}
	return min;
}

template<typename T>
T Max(T arr[], const int n)
{
	T max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
}
template<typename T>
T Max(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	T max = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] > max)max = arr[i][j];
		}

	}
	return max;
}

template<typename T>
void  ShiftLeft(T arr[], const int n, const int shifts)
{
	for (int i = 0; i < shifts; i++)
	{
		T buffer = arr[0];
		for (int i = 1; i < n; i++)
		{
			arr[i - 1] = arr[i];
		}
		arr[n - 1] = buffer;
	}
}
template<typename T>
void  ShiftRight(T arr[], const int n, const int shifts)
{
	ShiftLeft(arr, n, n - shifts);
}

void ShiftLeft(int arr[ROWS][COLS], const int ROWS, const int COLS, int shifts)
{
	//for (int i = 0; i < ROWS; i++)
	//{
		//ShiftLeft(arr[i], COLS, shifts);
	//}
	ShiftLeft(arr[0], ROWS * COLS, shifts); //Сквозной сдвиг
}


