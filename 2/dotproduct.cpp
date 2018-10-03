// dotproduct.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
void quick(vector<int> &v, int p, int r)
{
	int i, j, q;
	int x;
	int temp;
	if (p < r)
	{
		x = v[r];
		i = p - 1;
		for (j = p; j <= r - 1; j++)
		{
			if (v[j] >= x)
			{
				i++;
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
		temp = v[i + 1];
		v[i + 1] = v[r];
		v[r] = temp;
		q = i + 1;
		quick(v, p, q - 1);
		quick(v, q + 1, r);
	}
}

long long max_dot_product(vector<int> a, vector<int> b, int n) 
{
	long long result = 0;
	quick(a, 0, n - 1);
	quick(b, 0, n - 1);
	for (size_t i = 0; i < n; i++) 
	{
		result += ((long long)a[i]) * b[i];
	}
	return result;
}

int main() 
{
	size_t n;
	cin >> n;
	vector<int> a(n), b(n);
	for (size_t i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (size_t i = 0; i < n; i++) {
		cin >> b[i];
	}
	cout << max_dot_product(a, b, n) << std::endl;
	system("pause");
	return 0;
}
