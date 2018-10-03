// lcm.cpp: 定义控制台应用程序的入口点。
//

#include <iostream>
using namespace std;
/*
long long lcm_naive(int a, int b) {
	for (long l = 1; l <= (long long)a * b; ++l)
		if (l % a == 0 && l % b == 0)
			return l;

	return (long long)a * b;
}
*/
long long gcd_fast(long long a, long long b)
{
	if (a%b == 0)
		return b;
	else
		gcd_fast(b, a%b);
}
long long lcm_fast(long long a, long long b)
{
	long long gcd;
	gcd=gcd_fast(a, b);
	return ((a*b) / gcd);
	}

int main() {
	long long a, b;
	cin >> a >> b;
	cout << lcm_fast(a, b) << endl;
	system("pause");
	return 0;
}
