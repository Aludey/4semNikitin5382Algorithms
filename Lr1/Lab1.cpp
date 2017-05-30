#include "stdafx.h"
#include "Sort.h"





int _tmain(int argc, _TCHAR* argv[])
{
	int size = 0;
	cout << "Enter size of massive: ";
	cin >> size;
	vector<int> arr(size);
	input(arr, size);
	cout << endl;
	//output(arr, size);
	int start = clock();
	sort(arr);
	int end = clock();
	cout <<endl<<endl<< "Time: " << (float)(end - start) / CLOCKS_PER_SEC<<" seconds";
	cout << endl << endl;
	//output(arr, size);
	cout << endl;
	system("pause");
	return 0;
}