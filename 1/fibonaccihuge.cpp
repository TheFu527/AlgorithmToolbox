// fibonaccihuge.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
/*long long get_fibonacci_huge_naive(long long n, long long m) {
	if (n <= 1)
		return n;

	long long previous = 0;
	long long current = 1;

	for (long long i = 0; i < n - 1; ++i) {
		long long tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
	}

	return current % m;
}


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
*/
int get_fibonacci_huge_fast(long long n, long long m)
{
	vector<int>mod;
	int i,end=n;
	int real_n;
	mod.push_back(0 % m);
	mod.push_back(1 % m);
	for (i = 2; i <= n; i++)
	{
		mod.push_back((mod[i - 1] + mod[i - 2]) % m);
		if (i > 2 && mod[i - 2] == 0 && mod[i - 1] == 1)
		{
			end = i - 3;
			break;
		}
		//end = n;
	}
//	cout << end << "\n";
	real_n = n % (end + 1);
//	cout << fibonacci_fast(n) << "\n" << fibonacci_fast(real_n) << "\n";
	return mod[real_n];
}
int main() {
	long long n, m;
	cin >> n >> m;
	cout << get_fibonacci_huge_fast(n, m) << '\n';
	system("pause");
	return 0;
}

