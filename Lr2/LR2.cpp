// LR2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const int size = 3;
const int ttlsqs = size*size;
int sum = size*(size*size+1)/2;
int square[size][size];
bool possible[ttlsqs];
int squarecounter = 0;

void magicsquare(int square[size][size],const int size){
	//зануляем
	for (int i = 0; i < size; ++i){ 
		for (int j = 0; j < size; ++j)square[i][j] = 0;
	}
	//начинаем со всеми возможными номерами
	for (int i = 0; i < ttlsqs; ++i) possible[i] = true;
}

bool checkrows(int square[size][size], const int size){
	for (int i = 0; i < size; i++){
		int test = 0;
		bool unfilled = false;
		for (int j = 0; j < size; j++){
			test += square[i][j];
			if (square[i][j] == 0) unfilled = true;
		}
		if ((!unfilled) && (test != sum))return false;
	}
	return true;
}

bool checkcols(int square[size][size], const int size){
	for (int i = 0; i < size; i++){
		int test = 0;
		bool unfilled = false;
		for (int j = 0; j < size; j++){
			test += square[j][i];
			if (square[j][i] == 0) unfilled = true;
		}
		if ((!unfilled) && (test != sum))return false;
	}
	return true;
}

bool checkdiags(int square[size][size], const int size){
	int test1 = 0;
	int test2 = 0;
	bool unfilled = false;
	for (int i = 0; i < size; i++){
		test1 += square[i][i];
		test2 += square[i][size - i - 1];
		if (square[i][i] == 0) unfilled = true;
	}
	if ((!unfilled) && ((test1 != sum) || (test2 != sum)))return false;
	return true;
}


void fill(int square[size][size], const int size, int row, int col){
	if (!checkrows(square, size) || !checkcols(square, size) || !checkdiags(square, size)) return;
	if (row == size){
		cout << endl << "=====" << endl;
		for (int i = 0; i < size; ++i){
			for (int j = 0; j < size; ++j){
				cout << square[i][j]<<" ";
			}
			cout << endl;
		}
		cout << "=====" << endl;
		squarecounter++;
		return;
	}
	for (int i = 0; i < ttlsqs; i++){
		if (possible[i]){
			square[row][col] = i + 1;
			possible[i] = false;
			int newcol = col + 1;
			int newrow = row;
			if (newcol == size){
				newrow++;
				newcol = 0;
			}
			fill(square, size, newrow, newcol);
			square[row][col] = 0;
			possible[i] = true;
		}
	}
}


int main() {
	magicsquare(square, size);
	fill(square, size, 0, 0);
	cout << endl <<"Total quantity of squares: "<< squarecounter<<endl;
	system("pause");
}

