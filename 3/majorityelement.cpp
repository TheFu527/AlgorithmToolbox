// majorityelement.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int get_majority_element(vector<int> &a) 
{
	//if (left == right) return -1;
	//if (left + 1 == right) return a[left];
	int curIdx = 0, count = 1;
	int i;
	for (i = 1; i < a.size(); ++i)
	{
		a[i] == a[curIdx] ? ++count : --count;
		if (!count)
		{
			curIdx = i;
			count = 1;
		}
	}
	count = 0;
	for (i = 0; i < a.size(); ++i)
	{
		if (a[i] == a[curIdx])
			count++;
	}
	if (count > (a.size() / 2))
		return 1;
	return 0;
	//return -1;
	
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		cin >> a[i];
	}
	//cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
	cout << get_majority_element(a) << '\n';
	system("pause");
	return 0;
}
