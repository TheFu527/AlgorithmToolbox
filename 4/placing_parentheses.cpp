// placing_parentheses.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include <climits>

using namespace std;

long long eval(long long a, long long b, char op)
{
	if (op == '*')
	{
		return a * b;
	}
	else if (op == '+')
	{
		return a + b;
	}
	else if (op == '-')
	{
		return a - b;
	}
	else
	{
		assert(0);
	}
}

void find_num(string exp, vector<int> &num, vector<char> &ops)
{
	stringstream stoi;
	int i;
	for (i = 0; i < exp.size(); i++)
	{
		if (exp[i] != '+'&&exp[i] != '-'&&exp[i] != '*')
		{
			stoi << exp[i];
			int a;
			stoi >> a;
			stoi.clear();
			num.push_back(a);
		}
		else
		{
			stoi << exp[i];
			char b;
			stoi >> b;
			stoi.clear();
			ops.push_back(b);
		}
	}
}

long long minabc(long long v, long long w, long long x, long long y, long long z)
{
	if (v <= w && v <= x && v <= y && v <= z)
		return v;
	else if (w <= x && w <= y && w <= z)
		return w;
	else if (x <= y && x <= z)
		return x;
	else if (y <= z)
		return y;
	else
		return z;
}

long long maxabc(long long v, long long w, long long x, long long y, long long z)
{
	if (v >= w && v >= x && v >= y && v >= z)
		return v;
	else if (w >= x && w >= y && w >= z)
		return w;
	else if (x >= y && x >= z)
		return x;
	else if (y >= z)
		return y;
	else
		return z;
}

vector<long long> minandmax(int i, int j, vector<vector<long long> > max_val, vector<vector<long long> > min_val, vector<char> ops)
{
	vector<long long> m(2);
	long long max, min;
	min = LLONG_MAX;
	max = LLONG_MIN;
	long long a, b, c, d;
	int s;
	for (s = i; s < j; s++)
	{
		//cout <<"i!=j:i j s"<<i<<" " <<j<<" "<<s<<endl;
		//cout << i << " " << s << endl;
		//cout << max_val[i][s] << " " << max_val[s + 1][j] << " " << ops[s] << endl;
		a = eval(max_val[i][s], max_val[s + 1][j], ops[s]);
		b = eval(max_val[i][s], min_val[s + 1][j], ops[s]);
		c = eval(min_val[i][s], max_val[s + 1][j], ops[s]);
		d = eval(min_val[i][s], min_val[s + 1][j], ops[s]);
		//cout << "a b c d: " << a << " " << b << " " << c << " " << d << endl;
		min = minabc(min, a, b, c, d);
		//cout << "now min: " << min << endl;
		max = maxabc(max, a, b, c, d);
		//cout << "now max: " << max << endl;
	}
	//cout << "min and max:" << min << " " << max << endl;
	m[0] = min;
	m[1] = max;
	return m;
}

long long get_maximum_value(const string &exp)
{
	vector<int> num;
	vector<char> ops;
	vector<long long> m;
	find_num(exp, num, ops);
	int i, j, k;
	vector<vector<long long> > max_val(num.size());
	vector<vector<long long> > min_val(num.size());
	for (i = 0; i < num.size(); i++)
	{
		max_val[i].resize(num.size());
		max_val[i][i] = num[i];
		min_val[i].resize(num.size());
		min_val[i][i] = num[i];
	}
	/*
	for (i = 0; i < num.size(); i++)
	{
		for (j = 0; j < num.size(); j++)
			cout << max_val[i][j] << " ";
		cout << endl;
	}
	*/
	for (k = 1; k < (int)num.size(); k++)
	{
		for (i = 0; i < (int)num.size() - k; i++)
		{
			j = i + k;
			m = minandmax(i, j, max_val, min_val, ops);
			min_val[i][j] = m[0];
			max_val[i][j] = m[1];
		}
	}
	/*
	for (i = 0; i < num.size(); i++)
	{
		for (j = 0; j<num.size(); j++)
			cout << min_val[i][j] << " ";
		cout << endl;
	}
	*/
	return max_val[0][num.size() - 1];
}

int main()
{
	string s;
	cin >> s;
	cout << get_maximum_value(s) << '\n';
	system("pause");
	return 0;
}
