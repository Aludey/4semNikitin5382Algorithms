// KURS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;
ifstream in("in.txt");
ofstream out("out.txt");

int heightdiap = 25;
struct edge{
	int x, y, w;
	edge(){}
	edge(int x, int y, int w) :x(x), y(y), w(w){}
};

bool cmp(const edge& a, const edge& b){
	return a.w < b.w;
}

vector <int> leader;
int getLeader(int x){
	if (x == leader[x])return x;
	return leader[x] = getLeader(leader[x]);
}

bool unite(int x, int y){
	x = getLeader(x);
	y = getLeader(y);
	if (x == y)return false;
	if (rand() % 2 == 0) swap(x, y);
	leader[x] = y;
	return true;
}

void generate(vector <edge> &e, int m, int n){
	for (int i = 0; i < n; ++i){
		e[i].x = i;
		if ((i + 1) == n) e[i].y = 0;
		else e[i].y = i + 1;
		e[i].w = rand() % heightdiap + 1;
	}
	for (int i = n; i < m; ++i){
		e[i].x = rand() % n;
		e[i].y = rand() % n;
		while (e[i].y == e[i].x) e[i].y = rand() % n;
		e[i].w = rand() % heightdiap + 1;
		for (int j = 0; j < i; ++j){
			if (((e[j].x == e[i].x) && (e[j].y == e[i].y)) || ((e[j].x == e[i].y) && (e[j].y == e[i].x))){
				i--; j = i - 1;

			}
		}
	}
}

void print(vector <edge> e, int size){
	for (int i = 0; i < size; ++i){
		cout << endl << "Из " << e[i].x+1 << " вершины в " << e[i].y+1 << " вершину ребро длиной " << e[i].w;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int n=0, m=0;
	cout << "Введите количество вершин: ";
	cin >> n;
	cout << "Введите количество ребер в графе ( в диапазоне ("<<n<<","<<n*(n-1)/2<<"] ): ";
	cin >> m;
	while ((m <= n) || (m>n*(n - 1) / 2)){
		cin.clear();
		cin.ignore(225, '\n');
		cout << "Недопустимое число, введите число удовлетворяющее диапазону (" << n << "," << n*(n - 1) / 2 << "]" << endl << endl;
		cin >> m;
	}
	vector <edge> e(m);
	generate(e, m, n);
	print(e, m);
	float start = clock();
	sort(e.begin(), e.end(), cmp);
	leader.resize(n);
	for (int i = 0; i < n; ++i)leader[i] = i;
	vector <edge> ans;
	for (int i = 0; i < m; ++i){
		int x = e[i].x, y = e[i].y;
		if (unite(x, y)) ans.push_back(e[i]);
	}
	float end = clock();
	cout << endl << endl << "Time: " << (float)(end - start) / 1000 << " seconds";
	cout << endl << endl << "Остовное дерево: " << endl;
	print(ans, ans.size());
	int sum = 0;
	for (int i = 0; i < ans.size(); ++i)
		sum += ans[i].w;
	cout <<endl<<endl<<"Итоговый вес остовного дерева: "<< sum << endl<<endl;
	system("pause");
	return 0;
}

