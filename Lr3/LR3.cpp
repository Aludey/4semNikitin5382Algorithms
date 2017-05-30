#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;


const int MAXINT = 1000;

void check(int **arr, int *work, int n)
{
	int* RowSumm = new int[n];//индекс - работник, значение-работа
	int* ColSumm = new int[n];
	for (int count = 0; count < n; count++){
		RowSumm[count] = 0;
		ColSumm[count] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t ";
		}
		cout << endl;
	}
	cout << "--------------------------------" << endl;
	int minzp = 0;
	for (int i1 = 0; i1 < n; i1++)
	{
		for (int j1 = 0; j1 < n; j1++)
		{
			int minRow = MAXINT, minCol = MAXINT, sumRow = 0, sumCol = 0;
			for (int i = i1 + 1; i < n - i1; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (i != i1 && j != j1)
					{
						if ((j == n - 1 && j != j1) || (j == n - 2 && j + 1 == j1))
						{
							if (minRow>arr[i][j]){ sumRow = sumRow + arr[i][j]; }
							else if (minRow != MAXINT) { sumRow = minRow + sumRow; }
							minRow = MAXINT;
						}
						else if (minRow>arr[i][j])minRow = arr[i][j];
					}
				}
			}
			for (int j = 0; j < n; j++)
			{
				for (int i = i1 + 1; i < n - i1; i++)
				{
					if (i != i1 && j != j1)
					{
						if ((i == n - 1 && i != i1) || (i == n - 2 && i + 1 == j1))
						{
							if (minCol>arr[i][j]){ sumCol = sumCol + arr[i][j]; }
							else if (minCol != MAXINT){ sumCol = minCol + sumCol; }
							minCol = MAXINT;
						}
						else if (minCol>arr[i][j])minCol = arr[i][j];
					}
				}
			}
			RowSumm[j1] = sumRow + arr[i1][j1];
			ColSumm[j1] = sumCol + arr[i1][j1];
			for (int m = 0; m<n; m++){
				if (work[m]<n + 1 && work[m]>0){ RowSumm[work[m] - 1] = MAXINT; ColSumm[work[m] - 1] = MAXINT; }
			}
		}
		int min1 = RowSumm[0];
		for (int j = 0; j < n; j++)
		{
			if (RowSumm[j]<ColSumm[j])
			{
				if (min1 >= RowSumm[j]) { min1 = RowSumm[j]; work[i1] = j + 1; }
			}
			else
			{
				if (min1 >= ColSumm[j]){ min1 = ColSumm[j]; work[i1] = j + 1; }

			}
		}
		cout << i1 + 1 << " wroker placed on " << work[i1] << " job" << endl;
		minzp = minzp + arr[i1][work[i1] - 1];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == i1 || j == work[i1] - 1)arr[i][j] = MAXINT;
			}

		}
	}
	cout << endl << "Total cost (min) = " << minzp << endl;
	cout << endl;
}

int main()

{
	int n=0;
	cout << "Enter quantity of workers: ";
	cin >> n;
	while (!cin){
		cin.clear();
		while (cin.get() != '\n') continue;
		cout << "Enter a number, try again: ";
		cin >> n;
	}
	int **arr; //массив стоимостей
	arr = new int*[n];
	for (int i = 0; i < n; i++) arr[i] = new int[n];
	srand(time(0));
	
for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) arr[i][j] = rand() % 20+1;
	int* work = new int[n]; //массив распределеиня работников по работам
	for (int count = 0; count < n; count++) work[count] = -1;
	check(arr, work, n);

	system("pause");
	return 0;
}

