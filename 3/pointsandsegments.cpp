// pointsandsegments.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
struct Point
{
	char name;
	int pos;
	int number;
};

vector<Point> input_p(vector<int> starts, vector<int> ends, vector<int> points)
{
	int i;
	int n = starts.size() * 2 + points.size();
	vector<Point> all_point(n);
	for (i = 0; i<points.size(); i++)
	{
		all_point[i].name = 'b';
		all_point[i].pos = points[i];
		all_point[i].number = i;
	};
	for (i = 0; i<starts.size(); i++)
	{
		all_point[i + points.size()].name = 'a';
		all_point[i + points.size()].pos = starts[i];
	}
	for (i = 0; i<starts.size(); i++)
	{
		all_point[i + points.size() + starts.size()].name = 'c';
		all_point[i + points.size() + starts.size()].pos = ends[i];
	}
	return all_point;
}


void count_sort(vector<Point>&a, int l, int r)
{
	int i;
	int cnt_a = 0, cnt_b = 0, cnt_c = 0;
	vector<int> b_number;
	for (i = l; i <= r; i++)
	{
		if (a[i].name == 'a')
			cnt_a++;
		if (a[i].name == 'b')
		{
			cnt_b++;
			b_number.push_back(a[i].number);
		}
		if (a[i].name == 'c')
			cnt_c++;
	}
	i = l;
	int j = 0;
	while (cnt_a != 0)
	{
		a[i].name = 'a';
		cnt_a--;
		i++;
	}
	while (cnt_b != 0)
	{
		a[i].name = 'b';
		a[i].number = b_number[j];
		j++;
		cnt_b--;
		i++;
	}
	while (cnt_c != 0)
	{
		a[i].name = 'c';
		cnt_c--;
		i++;
	}
}

void quick3_sort(vector<Point> &a, int l, int r)
{
	if (l >= r)
		return;
	int k = l + rand() % (r - l + 1);
	swap(a[l], a[k]);
	int lt, gt;
	lt = l;
	gt = r + 1;
	int i = l + 1;
	int x = a[l].pos;
	while (i < gt)
	{
		if (a[i].pos < x)
		{
			swap(a[i], a[lt + 1]);
			i++;
			lt++;
		}
		else if (a[i].pos > x)
		{
			swap(a[i], a[gt - 1]);
			gt--;
		}
		else
			i++;
	}
	swap(a[l], a[lt]);
	quick3_sort(a, l, lt - 1);
	count_sort(a, lt, gt - 1);
	quick3_sort(a, gt, r);

}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points)
{
	vector<int> cnt(points.size());
	vector<Point> all_point = input_p(starts, ends, points);
	quick3_sort(all_point, 0, all_point.size() - 1);
	int i;
	/*
	for (i = 0; i < all_point.size(); i++)
	{
		cout << all_point[i].pos << " " << all_point[i].name << "\n";
	}
	*/
	int sum_a = 0, sum_c = 0;
	for (i = 0; i < all_point.size(); i++)
	{
		if (all_point[i].name == 'a')
			sum_a++;
		if (all_point[i].name == 'c')
			sum_c++;
		if (all_point[i].name == 'b')
			cnt[all_point[i].number] = sum_a - sum_c;
	}
	return cnt;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> starts(n), ends(n);
	for (size_t i = 0; i < starts.size(); i++)
	{
		cin >> starts[i] >> ends[i];
	}
	vector<int> points(m);
	for (size_t i = 0; i < points.size(); i++)
	{
		cin >> points[i];
	}
	vector<int> cnt = fast_count_segments(starts, ends, points);
	for (size_t i = 0; i < cnt.size(); i++) 
	{
		cout << cnt[i] << ' ';
	}
	system("pause");
	return 0;
}