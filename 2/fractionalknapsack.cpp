// fractionalknapsack.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void quick(vector<double> &v, int p, int r, vector<int> &weights)
{
	int i, j, q;
	double x;
	double temp;
	int temp_w;
	if (p < r)
	{
		x = v[r];
		i = p - 1;
		for (j = p; j <= r - 1; j++)
		{
			if (v[j] >= x)
			{
				i++;
				temp = v[i];
				temp_w = weights[i];
				v[i] = v[j];
				weights[i] = weights[j];
				v[j] = temp;
				weights[j] = temp_w;
			}
		}
		temp = v[i+1];
		temp_w = weights[i+1];
		v[i+1] = v[r];
		weights[i+1] = weights[r];
		v[r] = temp;
		weights[r] = temp_w;
		q = i + 1;
		quick(v, p, q - 1, weights);
		quick(v, q + 1, r, weights);
	}
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values, int n)
{
	double value = 0.0;
	vector<double>v(n);
	int i;
	for (i = 0; i < n; i++)
		v[i] =((double)values[i] / (double)weights[i]);
	quick(v, 0, n-1, weights);
	for (i = 0; i < n; i++)
	{
		if (capacity >= weights[i])
		{
			value += v[i] * weights[i];
			capacity -= weights[i];
		}
		else
		{
			value += v[i] * capacity;
			capacity = 0;
		}
		if (capacity == 0)
			break;
	}
	for (i = 0; i++; i < n)
	{
		cout << v[i] << " " << weights[i] << "\n";
	}
	return value;
}

int main() {
	int n;
	int capacity;
	cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) 
	{
		cin >> values[i] >> weights[i];
	}
	double optimal_value = get_optimal_value(capacity, weights, values, n);
	cout.precision(10);
	cout << optimal_value << endl;
	system("pause");
	return 0;
}