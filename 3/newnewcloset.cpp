// newnewcloset.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

struct Point
{
	int x, y;
};

int compareX(const void* a, const void* b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->x - p2->x);
}

int compareY(const void* a, const void* b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->y - p2->y);
}

double dist(Point p1, Point p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
		(p1.y - p2.y)*(p1.y - p2.y)
	);
}


double bruteForce(vector<Point> P, int n)
{
	double min = DBL_MAX;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (dist(P[i], P[j]) < min)
				min = dist(P[i], P[j]);
	return min;
}

double min(double x, double y)
{
	return (x < y) ? x : y;
}

double stripClosest(Point strip[], int size, double d)
{
	double min = d;
	for (int i = 0; i < size; ++i)
		for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
			if (dist(strip[i], strip[j]) < min)
				min = dist(strip[i], strip[j]);
	return min;
}


double closestUtil(vector<Point> Px, Point Py, int n)
{
	if (n <= 3)
		return bruteForce(Px, n);
	int mid = n / 2;
	Point midPoint = Px[mid];

	vector<Point> Pyl(mid + 1);
	vector<Point> Pyr(n - mid - 1);
	int li = 0, ri = 0;
	for (int i = 0; i < n; i++)
	{
		if (Py[i].x <= midPoint.x)
			Pyl[li++] = Py[i];
		else
			Pyr[ri++] = Py[i];
	}

	double dl = closestUtil(Px, Pyl, mid);
	double dr = closestUtil(Px + mid, Pyr, n - mid);

	double d = min(dl, dr);

	vector<Point> strip(n);
	int j = 0;
	for (int i = 0; i < n; i++)
		if (abs(Py[i].x - midPoint.x) < d)
			strip[j] = Py[i], j++;

	return min(d, stripClosest(strip, j, d));
}

double closest(vector<Point> P, int n)
{
	vector<Point> Px(n);
	vector<Point> Py(n);
	for (int i = 0; i < n; i++)
	{
		Px[i] = P[i];
		Py[i] = P[i];
	}

	qsort(Px, n, sizeof(Point), compareX);
	qsort(Py, n, sizeof(Point), compareY);

	return closestUtil(Px, Py, n);
}

int main()
{
	size_t n;
	std::cin >> n;
	vector<Point> P(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> P[i].x >> P[i].y;
	}
	cout << fixed;
	cout << std::setprecision(9) << closest(P, n) << "\n";
}