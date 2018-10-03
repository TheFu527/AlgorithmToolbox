// coveringsegments.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment {
	int start, end;
};

void quick(vector<Segment> &v, int p, int r)
{
	int i, j, q;
	int x;
	int temp;
	if (p < r)
	{
		x = v[r].end;
		i = p - 1;
		for (j = p; j <= r - 1; j++)
		{
			if (v[j].end <= x)
			{
				i++;
				temp = v[i].start;
				v[i].start = v[j].start;
				v[j].start = temp;
				temp = v[i].end;
				v[i].end = v[j].end;
				v[j].end = temp;
			}
		}
		temp = v[i + 1].start;
		v[i + 1].start = v[r].start;
		v[r].start = temp;
		temp = v[i + 1].end;
		v[i + 1].end = v[r].end;
		v[r].end = temp;
		q = i + 1;
		quick(v, p, q - 1);
		quick(v, q + 1, r);
	}
}

vector<int> optimal_points(vector<Segment> &segments)
{
	quick(segments, 0, segments.size() - 1);
	vector<int> points;
	points.push_back(segments[0].end);
	for (size_t i = 1; i < segments.size(); i++)
	{
		if (points.back() < segments[i].start)
		{
			points.push_back(segments[i].end);
		}

	}

	/*
	for (size_t i = 0; i < segments.size(); ++i) 
	{
		points.push_back(segments[i].start);
		points.push_back(segments[i].end);
	}
	*/

	return points;
}

int main() 
{
	int n;
	cin >> n;
	vector<Segment> segments(n);
	for (size_t i = 0; i < segments.size(); ++i) {
		cin >> segments[i].start >> segments[i].end;
	}
	vector<int> points = optimal_points(segments);
	cout << points.size() << "\n";
	for (size_t i = 0; i < points.size(); ++i) {
		cout << points[i] << " ";
	}
	system("pause");
	return 0;
}
