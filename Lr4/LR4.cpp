// LR4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "gtest/gtest.h"

using namespace std;

int min(int a, int b)
{
	if (a < b)return a;
	else return b;
}

int minnumchar(char str[], int l, int r)
{
	if (l == r) return 0;
	if (l > r) { cout << "Error"; return INT_MAX; }
	if (l == r - 1){
		if (str[l] == str[r]) return 0;
		else 1;
	}
	if (str[l] == str[r]) return minnumchar(str, l + 1, r - 1);
	else return (min(minnumchar(str, l, r - 1), minnumchar(str, l + 1, r)) + 1);
}

TEST(Strings_test, string1){
	char *str = "abba";
	int tmp = minnumchar(str, 0, strlen(str) - 1);
	EXPECT_EQ(0, tmp);
}
TEST(Strings_test, string2){
	char *str = "abbca";
	int tmp = minnumchar(str, 0, strlen(str) - 1);
	EXPECT_EQ(1, tmp);
}
TEST(Strings_test, string3){
	char *str = "145434131";
	int tmp = minnumchar(str, 0, strlen(str) - 1);
	EXPECT_EQ(4, tmp);
}
TEST(Strings_test, string4){
	char *str = "ASjdf34awSA";
	int tmp = minnumchar(str, 0, strlen(str) - 1);
	EXPECT_EQ(6, tmp);
}
TEST(Strings_test, string5){
	char *str = "o12sgFSDjer34ioFJYr52";
	int tmp = minnumchar(str, 0, strlen(str) - 1);
	EXPECT_EQ(16, tmp);
}


int _tmain(int argc, _TCHAR* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}

