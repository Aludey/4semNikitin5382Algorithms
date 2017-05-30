
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <time.h>

using namespace std;

template <typename T>
void mergesort(vector<T> &arr, int left, int right){										//left - левая граница исходного массива
	if (right - left > 0){																	//right - правая граница исходного массива
		int delimiter = (right + left) / 2;													//delimiter - медиана массива
		mergesort(arr, left, delimiter);													//разбиение на два меньших подмассива; итерирует до тех пор, пока размер подмассивов > 1
		mergesort(arr, delimiter + 1, right);
		if (right - left == 1){								//если всего два э-та, то сравниваются "номиналы" и при необходимости меняются местами
			if (arr[left] > arr[right]) swap(arr[left], arr[right]);
			return;
		}
		vector<T> helparr(&arr[left], &arr[right] + 1);
		for (int idx = left, lidx = 0, ridx = delimiter - left + 1; idx <= right; ++idx){	//idx - счетчик текущего э-та строящегося массива
			if (lidx > delimiter - left){													//lidx - счетчик пробега по "левому" массиву из двух
				arr[idx] = helparr[ridx++];													//ridx - счетчик пробега по "правому" массиву из двух
			}
			else{																			//если кончился левый или правый подмассив, то остаток другого подмассива прикрепляется к итоговому массиву
				if (ridx > right - left){
					arr[idx] = helparr[lidx++];
				}
				else{
					if (helparr[ridx] < helparr[lidx]){										//добаление в массив очередного меньшего э-та
						arr[idx] = helparr[ridx++];
					}
					else arr[idx] = helparr[lidx++]; 
				}
			}
		}
	}
	else return;
}

template <typename T>
void sort(vector<T> &arr){
	mergesort(arr, 0, (int)(arr.size() - 1));
}

template <typename T>
void input(vector<T> &arr, int size){
	int a, b;
	cout<<endl << "Enter left border of random: ";
	cin >> a;
	cout << endl << "Enter right border of random: ";
	cin >> b;
	for (int i = 0; i < size; ++i){
		arr[i]= a + rand() % b;
	}
	return;
}
template <typename T>
void output(vector<T> &arr, int size){
	for (int i = 0; i < size; ++i){
		cout << arr[i] << " ";
	}
}