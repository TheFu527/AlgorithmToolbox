// edit_distance.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int edit_distance(const string &str1, const string &str2)
{
	//write your code here
	vector<vector<int> > a(str1.size()+1);
	int i, j;
	int del, ins, sub;
	for (i = 0; i < str1.size() + 1; i++)
	{
		a[i].resize(str2.size() + 1);
		a[i][0] = i;
	}
	for (j = 0; j < str2.size() + 1; j++)
		a[0][j] = j;
	for (i = 1; i <= str1.size(); i++)
	{
		for (j = 1; j <= str2.size(); j++)
		{
			del = a[i - 1][j] + 1;
			ins = a[i][j - 1] + 1;
			if (str1[i - 1] == str2[j - 1])
				sub = a[i - 1][j - 1];
			else
				sub = a[i - 1][j - 1] + 1;
			a[i][j] = min<int>(del, min<int>(ins, sub));
		}
	}
	
	for (i = 1; i <= str1.size(); i++)
	{
		for (j = 1; j <= str2.size(); j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
	return a[str1.size()][str2.size()];
}

int main()
{
	string str1;
	string str2;
	cin >> str1 >> str2;
	cout << edit_distance(str1, str2) << std::endl;
	system("pause");
	return 0;
}
