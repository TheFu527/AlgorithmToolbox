// differentsummands.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

vector<int> optimal_summands(int n) 
{
	vector<int> summands;
	int k = n, l = 1;
	while (k > 2*l)
	{
		summands.push_back(l);
		k = k - l;
		l += 1;
	}
	summands.push_back(k);
	return summands;
}

int main() 
{
	int n;
	cin >> n;
	vector<int> summands = optimal_summands(n);
	cout << summands.size() << '\n';
	for (size_t i = 0; i < summands.size(); ++i) 
	{
		cout << summands[i] << ' ';
	}
	system("pause");
	return 0;
}
