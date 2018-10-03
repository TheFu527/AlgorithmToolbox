// fibonaccilastdigit.cpp: 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

/*
int get_fibonacci_last_digit_naive(int n) {
	if (n <= 1)
		return n;

	int previous = 0;
	int current = 1;

	for (int i = 0; i < n - 1; ++i) {
		int tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
	}

	return current % 10;
}
*/

int get_fibonacci_last_digit_fast(int n)
{
	vector<int>a;
	int i;
	a.push_back(1);
	a.push_back(1);
	for (i = 2; i < n; i++)
	{
		a.push_back((a[i - 1] + a[i - 2]) % 10);
	}
	return a[n-1];
}

int main() 
{
	int n;
	cin >> n;
	int c = get_fibonacci_last_digit_fast(n);
	cout << c << '\n';
	system("pause");
	return 0;
}
