// gcd.cpp: 定义控制台应用程序的入口点。
//


#include <iostream>
using namespace std;
/*
int gcd_naive(int a, int b) {
	int current_gcd = 1;
	for (int d = 2; d <= a && d <= b; d++) {
		if (a % d == 0 && b % d == 0) {
			if (d > current_gcd) {
				current_gcd = d;
			}
		}
	}
	return current_gcd;
}
*/
int gcd_fast(int a, int b)
{
	if (a%b == 0)
		return b;
	else
		gcd_fast(b, a%b);
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << gcd_fast(a, b) << endl;
	system("pause");
	return 0;
}
