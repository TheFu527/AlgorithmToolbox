// inversions.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int>&a, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	vector<int>left_a(n1+1);
	vector<int>right_a(n2+1);
	int i, j, k, x = 0;;
	long long number_of_inversions = 0;
	for (i = 0; i < n1; i++)
		left_a[i] = a[p + i];
	for (j = 0; j < n2; j++)
		right_a[j] = a[q + j + 1];
	/*
	for (i = 0; i < n1; i++)
	{
		for (j = x; j < n2; j++)
		{
			if (left_a[i] > right_a[j])
			{
				number_of_inversions += n2 - i + 1;
			}
			else
			{
				break;
			}
		}
		x = j;
	}
	*/
	i = j = 0;
	for (k = p; k <= r; k++)
	{
		if (i < n1&&j < n2)
		{
			if (left_a[i] <= right_a[j])
			{
				a[k] = left_a[i];
				i++;
			}
			else
			{
				a[k] = right_a[j];
				j++;
				number_of_inversions += n1 - i;
			}
		}
		else if (i < n1)
		{
			a[k] = left_a[i];
			i++;
		}
		else if (j < n2)
		{
			a[k] = right_a[j];
			j++;
		}
	}
	return number_of_inversions;
}
long long merge_sort(vector<int>&a, int p, int r)
{
	long long number_of_inversions = 0;
	if (p < r)
	{
		int q = (p + r) / 2;
		number_of_inversions += merge_sort(a, p, q);
		number_of_inversions += merge_sort(a, q + 1, r);
		number_of_inversions += merge(a, p, q, r);
	}
	return number_of_inversions;
 }

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
	long long number_of_inversions = 0;
	if (right <= left + 1) return number_of_inversions;
	size_t ave = left + (right - left) / 2;
	number_of_inversions += get_number_of_inversions(a, b, left, ave);
	number_of_inversions += get_number_of_inversions(a, b, ave, right);
	//write your code here

	return number_of_inversions;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); i++) 
	{
		cin >> a[i];
	}
	//merge_sort(a, 0, a.size() - 1);
	//for (size_t i = 0; i < a.size(); i++) 
	//{
		//cout << a[i] << " ";
	//}
	vector<int> b(a.size());
	//cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
	cout << merge_sort(a, 0, a.size() - 1) << '\n';
	system("pause");
	return 0;
}
