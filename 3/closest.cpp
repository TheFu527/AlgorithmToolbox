// closest.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;
/*
double naive_distance(vector<int> x, vector<int> y)
{
	int i, j;
	double min_dis = sqrt((x[0] - x[1])*(x[0] - x[1]) + (y[0] - y[1])*(y[0] - y[1]));
	for (i = 0; i < x.size(); i++)
		for (j = i + 1; j < x.size(); j++)
		{
			if (sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])) < min_dis)
				min_dis = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
		}
	return min_dis;
}
*/
void quick_sort(vector<int> &x, vector<int> &y, int l, int r)
{
	if (l >= r)
		return;
	int k = l + rand() % (r - l + 1);
	swap(x[l], x[k]);
	swap(y[l], y[k]);
	int lt, gt;
	lt = l;
	gt = r + 1;
	int i = l + 1;
	int z = x[l];
	while (i < gt)
	{
		if (x[i] < z)
		{
			swap(x[i], x[lt + 1]);
			swap(y[i], y[lt + 1]);
			i++;
			lt++;
		}
		else if (x[i] > z)
		{
			swap(x[i], x[gt - 1]);
			swap(y[i], y[gt - 1]);
			gt--;
		}
		else
			i++;
	}
	swap(x[l], x[lt]);
	swap(y[l], y[lt]);
	quick_sort(x, y, l, lt - 1);
	quick_sort(x, y, gt, r);
}



double mid_distance(vector<int> x, vector<int> y, vector<int> x_n, vector<int> y_n, double min_lr, int l, int r, int mid)
{
	/*
	int i, j;
	double min_dis = sqrt((x[l] - x[mid + 1])*(x[l] - x[mid + 1]) + (y[l] - y[mid + 1])*(y[l] - y[mid + 1]));
	for (i = l; i <= mid; i++)
		for (j = mid + 1; j <= r; j++)
			if (sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])) < min_dis)
				min_dis = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
	return min_dis;
	*/
	double dmid = (double)(x[mid] + x[mid + 1]) / 2;
	double dl = dmid - min_lr;
	double dr = dmid + min_lr;
	//cout << dl << " " << dr << "\n";
	vector<int> x1;
	vector<int> y1;
	int i,j;
	for (i = 0; i <x_n.size(); i++)
	{
		if (x_n[i] >= dl&&x_n[i] <= dr)
		{
			x1.push_back(x_n[i]);
			y1.push_back(y_n[i]);
		}
	}
	//for (i = 0; i < x1.size(); i++)
	//{
		//cout << x1[i] << " " << y1[i] << "\n";
	//}
	int k = 0;
	vector<int> x1_l;
	vector<int> y1_l;
	vector<int> x1_r;
	vector<int> y1_r;
	for (i = 0; i < x1.size(); i++)
	{
		if (x1[i] > dl&& x1[i] < dmid)
		{
			x1_l.push_back(x1[i]);
			y1_l.push_back(y1[i]);
		}
		else if (x1[i] == dmid)
		{
			for(j=l;j<mid;i++)
				if (y[j] == y1[i])
				{
					x1_l.push_back(x1[i]);
					y1_l.push_back(y1[i]);
					k = 1;
					break;
				}
			if (k == 0)
			{
				x1_r.push_back(x1[i]);
				y1_r.push_back(y1[i]);
			}
			k = 0;
		}
		else if(x1[i] > dmid&& x1[i] < dr)
		{
			x1_r.push_back(x1[i]);
			y1_r.push_back(y1[i]);
		}
	}
	
	double min_dis = min_lr;
	//cout << min_dis << ' ' << x1.size() << "\n";
	/*
	for (i = 0; i < (int)x1.size() - 1; i++)
		for (j = i + 1; j < i + 8; j++)
		{
			if (j >= x1.size())
				break;
			if (sqrt((x1[i] - x1[j])*(x1[i] - x1[j]) + (y1[i] - y1[j])*(y1[i] - y1[j])) < min_dis)
				min_dis = sqrt((x1[i] - x1[j])*(x1[i] - x1[j]) + (y1[i] - y1[j])*(y1[i] - y1[j]));
		}
	*/
	
	for(i=0;i<x1_l.size();i++)
		for(j=0;j<x1_r.size();j++)
			if (sqrt((x1_l[i] - x1_r[j])*(x1_l[i] - x1_r[j]) + (y1_l[i] - y1_r[j])*(y1_l[i] - y1_r[j])) < min_dis)
				min_dis = sqrt((x1_l[i] - x1_r[j])*(x1_l[i] - x1_r[j]) + (y1_l[i] - y1_r[j])*(y1_l[i] - y1_r[j]));
	
	return min_dis;
}


double find_min_dis(vector<int> x, vector<int> y, vector<int> x_n, vector<int> y_n, int l, int r)
{
	if (l == r - 1)
		return sqrt((x[l] - x[r])*(x[l] - x[r]) + (y[l] - y[r])*(y[l] - y[r]));
	if (l == r)
		return 1.0/0.0;
	int mid = (l + r) / 2;
	double min_l = find_min_dis(x, y, x_n, y_n, l, mid);
	double min_r = find_min_dis(x, y, x_n, y_n, mid+1, r);
	double min_lr = min<double>(min_l, min_r);
	//cout << min_lr << "\n";
	if (min_lr == 0)
		return 0;
	double min_m = mid_distance(x, y, x_n, y_n, min_lr, l, r, mid);
	//cout << min_m;
	return min<double>(min_lr, min_m);
}
double minimal_distance(vector<int> x, vector<int> y)
{
	double min_dis;
	quick_sort(x, y, 0, x.size() - 1);
	vector<int> x_n(x);
	vector<int> y_n(y);
	quick_sort(y_n, x_n, 0, x_n.size() - 1);
	min_dis = find_min_dis(x, y, x_n, y_n, 0, x.size() - 1);
	return min_dis;
}

int main()
{
	size_t n;
	cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	cout << fixed;
	//cout << setprecision(9) << naive_distance(x, y) << "\n";
	cout << setprecision(9) << minimal_distance(x, y) << "\n";
	system("pause");
	return 0;
}
