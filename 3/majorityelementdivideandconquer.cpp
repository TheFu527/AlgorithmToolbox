// majorityelementdivideandconquer.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int get_majority_element(vector<int> &a, int left, int right) 
{
	if (left == right) return a[left];
	if (left + 1 == right) return a[left];
	int mid = (left + right) / 2;
	int max_l, max_r, count_l = 0, count_r = 0;
	max_l = get_majority_element(a, left, mid);
	max_r = get_majority_element(a, mid + 1, right);
	if (max_l == max_r)
		return max_l;
	else
	{
		for (int i = left; i <= right; i++)
		{
			if (a[i] == max_l)
				count_l++;
			else if (a[i] == max_r)
				count_r++;
		}
	}
	if (count_l >= (float)(right - left) / 2 + 1)
		return max_l;
	else if (count_r >= (float)(right - left) / 2 + 1)
		return max_r;
	return -1;
}

int main() 
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		cin >> a[i];
	}
	cout << (get_majority_element(a, 0, a.size()-1) != -1) << '\n';
	system("pause");
	return 0;
}

