// primitive_calculator.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void bottom_up_1(int n, vector<int> &buzhou)
{
	int i;
	vector<int> step_min(n + 1);
	vector<int> step_3(n + 1);
	vector<int> step_2(n + 1);
	vector<int> step_1(n + 1);
	for (i = 2; i <= n; i++)
	{
		step_3[i] = i + 1;
		step_2[i] = i + 1;
		step_1[i] = i + 1;
		if (i % 3 == 0)
			step_3[i] = step_min[i / 3] + 1;
		if (i % 2 == 0)
			step_2[i] = step_min[i / 2] + 1;
		step_1[i] = step_min[i - 1] + 1;
		if (step_1[i] <= step_2[i] && step_1[i] <= step_3[i])
		{
			step_min[i] = step_1[i];
			buzhou.push_back(i - 1);
		}
		else if (step_2[i] <= step_1[i] && step_2[i] <= step_3[i])
		{
			step_min[i] = step_2[i];
			buzhou.push_back(i / 2);
		}
		else
		{
			step_min[i] = step_3[i];
			buzhou.push_back(i / 3);
		}
	}
}

vector<int> optimal_sequence_new(int n)
{
	vector<int> sequence;
	vector<int> buzhou;
	bottom_up_1(n, buzhou);
	int i = (int)buzhou.size() - 1;
	while (i >= 0)
	{
		sequence.push_back(buzhou[i]);
		i = buzhou[i] - 2;
	}
	reverse(sequence.begin(), sequence.end());
	sequence.push_back(n);
	return sequence;
}

int main()
{
	int n;
	cin >> n;
	vector<int> sequence = optimal_sequence_new(n);
	cout << sequence.size() - 1 << endl;
	for (size_t i = 0; i < sequence.size(); ++i)
	{
		cout << sequence[i] << " ";
	}
	system("pause");
	return 0;
}
