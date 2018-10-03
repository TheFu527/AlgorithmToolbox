// knapsack.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int W, const vector<int> &w)
{
	int i, j;
	vector<vector<int> > c(w.size()+1);
	for(i=0;i<w.size()+1;i++)
		c[i].resize(W+1);
	for (i = 1; i <= w.size(); i++)
		for (j = 1; j <= W; j++)
		{
			if (w[i-1] > j)
				c[i][j] = c[i-1][j];
			else
			{
				if (w[i-1] + c[i - 1][j - w[i-1]] > c[i - 1][j])
					c[i][j] = w[i-1] + c[i - 1][j - w[i-1]];
				else
					c[i][j] = c[i - 1][j];
			}

		}	
	/*
	for (i = 0; i < w.size()+1; i++)
	{
		for (j = 0; j <= W; j++)
			cout << c[i][j] << " ";
		cout << endl;
	}
	*/
	return c[w.size()][W];
}

int main() 
{
	int n, W;
	cin >> W >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++) 
	{
		cin >> w[i];
	}
	cout << optimal_weight(W, w) << '\n';
	system("pause");
	return 0;
}
