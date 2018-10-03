// binarysearch.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int binary_search(const vector<int> &a, int x,int left,int right) 
{
	int mid = left + (right - left) / 2;
	//cout << mid << "\n";
	if (left > right)
		return -1;
	if (a[mid] == x)
		return mid;
	else if (a[mid] > x)
		binary_search(a, x, left, mid - 1);
	else if (a[mid] < x)
		binary_search(a, x, mid + 1, right);
	
}
/*
int linear_search(const vector<int> &a, int x) {
	for (size_t i = 0; i < a.size(); ++i) {
		if (a[i] == x) return i;
	}
	return -1;
}
*/
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		cin >> a[i];
	}
	int m;
	std::cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < m; ++i) {
		//replace with the call to binary_search when implemented
		cout << binary_search(a, b[i],0, (int)a.size()-1) << ' ';
	}
	system("pause");
	return 0;
}
