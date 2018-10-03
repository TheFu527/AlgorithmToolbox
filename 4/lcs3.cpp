// lcs3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void zhijie(vector<int> num1, vector<int> num2, vector<int> num3)
{
	int i, j, k;
	vector<vector<vector<int> > > a;
	a.resize(num1.size() + 1);
	for (i = 0; i < num1.size() + 1; i++)
	{
		a[i].resize(num2.size() + 1);
		for (j = 0; j < num2.size() + 1; j++)
			a[i][j].resize(num3.size() + 1);
	}
	for (i = 1; i < num1.size() + 1; i++)
		for (j = 1; j < num2.size() + 1; j++)
			for (k = 1; k < num3.size() + 1; k++)
			{
				if (num1[i - 1] == num2[j - 1] && num2[j - 1] == num3[k - 1])
					a[i][j][k] = a[i - 1][j - 1][k - 1] + 1;
				else if (a[i - 1][j][k] >= a[i][j - 1][k] && a[i - 1][j][k] >= a[i][j][k - 1])
					a[i][j][k] = a[i - 1][j][k];
				else if (a[i][j - 1][k] >= a[i - 1][j][k] && a[i][j - 1][k] >= a[i][j][k - 1])
					a[i][j][k] = a[i][j - 1][k];
				else
					a[i][j][k] = a[i][j][k - 1];
			}
	cout << a[num1.size()][num2.size()][num3.size()];
}
/*
vector<int> lcs2(vector<int> num1, vector<int> num2)
{
	vector<vector<int> > a(num1.size() + 1);

	int i, j;
	for (i = 0; i < num1.size() + 1; i++)
		a[i].resize(num2.size() + 1);
	for(i=1;i<num1.size()+1;i++)
		for (j = 1; j < num2.size() + 1; j++)
		{
			if (num1[i - 1] == num2[j - 1])
			{
				a[i][j] = a[i - 1][j - 1] + 1;
			}
			else if(a[i][j-1]>=a[i-1][j])
			{
				a[i][j] = a[i][j - 1];
			}
			else
			{
				a[i][j] = a[i - 1][j];
			}
		}
	
}
*/
void lcs3(vector<int> &a, vector<int> &b, vector<int> &c) 
{
	zhijie(a, b, c);
	//return min(min(a.size(), b.size()), c.size());
}

int main() 
{
	size_t an;
	cin >> an;
	vector<int> a(an);
	for (size_t i = 0; i < an; i++) 
	{
		cin >> a[i];
	}
	size_t bn;
	cin >> bn;
	vector<int> b(bn);
	for (size_t i = 0; i < bn; i++) 
	{
		cin >> b[i];
	}
	size_t cn;
	cin >> cn;
	vector<int> c(cn);
	for (size_t  i = 0; i < cn; i++) 
	{
		cin >> c[i];
	}
	//cout << lcs3(a, b, c) << endl;
	lcs3(a, b, c);
	system("pause");
	return 0;
}
