// change.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
using namespace std;

int get_change(int m) 
{
	int a, b, c, n = 0;
	a = m / 10;
	m -= (a * 10);
	b = m / 5;
	m -= (b * 5);
	c = m / 1;
	n = a + b + c;
	return n;
}

int main() 
{
	int m;
	cin >> m;
	cout << get_change(m) << '\n';
	system("pause");
	return 0;
}

