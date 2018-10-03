// largestnumber.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
void quick(vector<string>&a, int p, int r)
{
	stringstream ret;
	string temp, x;
	int jx, xj;
	int q, j, i;
	if (p < r)
	{
		x = a[r];
		i = p - 1;
		for (j = p; j <= r - 1; j++)
		{
			ret << a[j] << x;
			ret >> jx;
			ret.clear();
			ret << x << a[j];
			ret >> xj;
			ret.clear();
			if (jx >= xj)
			{
				i++;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		temp = a[i + 1];
		a[i + 1] = a[r];
		a[r] = temp;
		q = i + 1;
		quick(a, p, q - 1);
		quick(a, q + 1, r);
	}
}

string largest_number(vector<string> a) 
{
	//write your code here
	stringstream ret;
	quick(a, 0, a.size() - 1);
	for (size_t i = 0; i < a.size(); i++) 
	{
		ret << a[i];
	}
	string result;
	ret >> result;
	return result;
}

int main() 
{
	int n;
	cin >> n;
	vector<string> a(n);
	for (size_t i = 0; i < a.size(); i++) 
	{
		cin >> a[i];
	}
	cout << largest_number(a);
	system("pause");
	return 0;
}
