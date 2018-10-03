// fibonaccipartialsum.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

/*long long get_fibonacci_partial_sum_naive(long long from, long long to) {
	if (to <= 1)
		return to;

	long long previous = 0;
	long long current = 1;

	for (long long i = 0; i < from - 1; ++i) {
		long long tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
	}

	long long sum = current;

	for (long long i = 0; i < to - from; ++i) {
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


int get_fibonacci_partial_sum_fast(long long from, long long to)
{
	int sum_from, sum_to;
	int mod_from = get_fibonacci_huge_fast(from + 1, 10);
	if (mod_from != 0)
		sum_from = mod_from - 1;
	else
		sum_from = 9;
	int mod_to = get_fibonacci_huge_fast(to + 2, 10);
	if (mod_to != 0)
		sum_to = mod_to - 1;
	else
		sum_to = 9;
	if (sum_to >= sum_from)
		return sum_to - sum_from;
	return (sum_to - sum_from) % 10 + 10;
}

int main() {
	long long from, to;
	cin >> from >> to;
	cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
	system("pause");
	return 0;
}