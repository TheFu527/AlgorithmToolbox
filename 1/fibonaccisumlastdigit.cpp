// fibonaccisumlastdigit.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<vector>
using namespace std;

/*
int fibonacci_sum_naive(long long n) {
	if (n <= 1)
		return n;

	long long previous = 0;
	long long current = 1;
	long long sum = 1;

	for (long long i = 0; i < n - 1; ++i) {
		long long tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
		sum += current;
	}

	return sum % 10;
}
*/

long long fibonacci_fast(int n) {
	int i;
	vector<long long>a;
	a.push_back(0);
	a.push_back(1);
	for (i = 2; i <= n; i++)
	{
		a.push_back(a[i - 1] + a[i - 2]);
	}
	return a[n];
}

int get_fibonacci_huge_fast(long long n, int m)
{
	vector<int>mod;
	int i, end = 0;
	int real_n;
	for (i = 0; i <= n; i++)
	{
		mod.push_back(fibonacci_fast(i) % m);
		if (i > 2 && mod[i - 2] == 0 && mod[i - 1] == 1)
		{
			end = i - 3;
			break;
		}
		end = n;
	}
	real_n = n % (end + 1);
	return mod[real_n];
}


int fibonacci_sum_fast(long long n)
{
	int mod = get_fibonacci_huge_fast(n+2, 10);//前n项求和等于F（n+2）-1
	if (mod != 0)
		return mod - 1;
	return 9;
}

int main() {
	long long n = 0;
	cin >> n;
	cout << fibonacci_sum_fast(n);
	system("pause");
	return 0;
}

