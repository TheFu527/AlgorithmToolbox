// sorting.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
/*
int partition2(vector<int> &a, int l, int r) 
{
	int x = a[l];
	int j = l;
	for (int i = l + 1; i <= r; i++) {
		if (a[i] <= x) {
			j++;
			swap(a[i], a[j]);
		}
	}
	swap(a[l], a[j]);
	return j;
}

int *partition3(vector<int>&a, int l, int r)
{
	int pos[2];
	pos[0] = l;
	pos[1] = r + 1;
	int i = l + 1;
	int x = a[l];
	while (i < pos[1])
	{
		if (a[i] < x)
		{
			swap(a[i], a[pos[0] + 1]);
			i++;
			pos[0]++;
		}
		else if (a[i] > x)
		{
			swap(a[i], a[pos[1] - 1]);
			pos[1]--;
		}
		else
			i++;
	}
	swap(a[l], a[pos[0]]);
	return pos;
}
*/
void randomized_quick_sort(vector<int> &a, int l, int r) {
	if (l >= r) {
		return;
	}

	int k = l + rand() % (r - l + 1);
	swap(a[l], a[k]);
	//int *m = partition3(a, l, r);
	int lt,gt;
	lt = l;
	gt = r + 1;
	int i = l + 1;
	int x = a[l];
	while (i < gt)
	{
		if (a[i] < x)
		{
			swap(a[i], a[lt + 1]);
			i++;
			lt++;
		}
		else if (a[i] > x)
		{
			swap(a[i], a[gt - 1]);
			gt--;
		}
		else
			i++;
	}
	swap(a[l], a[lt]);
	//cout << m[0] << " " << m[1] << "\n";
	//for (int i = 0; i <= r; i++)
		//cout << a[i] << " ";
	randomized_quick_sort(a, l, lt - 1);
	randomized_quick_sort(a, gt, r);
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		cin >> a[i];
	}
	randomized_quick_sort(a, 0, a.size() - 1);
	for (size_t i = 0; i < a.size(); ++i) {
		cout << a[i] << ' ';
	}
	system("pause");
	return 0;
}
