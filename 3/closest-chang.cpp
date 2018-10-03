#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::pair;
using std::min;
using std::swap;

struct Point
{
	int x;
	int y;
};

int partition2(vector<Point>&a, int l, int r) {
  int x = a[l].x;
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i].x <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort (vector <Point> &a, int l, int r) 
{
  if (l >= r)
    return;
  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);
  randomized_quick_sort (a, l, m - 1);
  randomized_quick_sort (a, m + 1, r);
}

int partition2_y(vector<Point>&a, int l, int r) {
  int x = a[l].y;
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i].y <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort_y (vector <Point> &a, int l, int r) 
{
  if (l >= r)
    return;
  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);
  randomized_quick_sort (a, l, m - 1);
  randomized_quick_sort (a, m + 1, r);
}

double distance(Point p0, Point p1)
{
	return sqrt(pow((p0.x-p1.x),2)+pow((p0.y-p1.y),2));
}

double mid_minimal_distance(vector<Point>X1,vector<Point>X2,vector<Point>Y, double delta)
{
  	int i, j;
    int k=0;
  	double m= ((double)X1[X1.size()-1].x+X2[0].x)/2;
  	vector<Point> Y1, Y2;
    if(X1.size()==0||X2.size()==0)
      return delta;
  	for(i=0; i<Y.size()-1; i++)
  	{
  		if((double)Y[i].x<m && (double)Y[i].x>m-delta)
  			Y1.push_back(Y[i]);
      else if((double)Y[i].x>m && (double)Y[i].x<m+delta)
        Y2.push_back(Y[i]);
      else if((double)Y[i].x==m)
      {  
        j=(int)X1.size()-1;
        while((double)X1[j].x==m && j>=0)
        {
          if(X1[j].y==Y[i].y)
          {
            Y1.push_back(Y[i]);
            k=1;
            break;
          }
          j--;
        }
        if(k==0)
          Y2.push_back(Y[i]);
      }
  	}

    for(i=0; i<Y1.size(); i++)
      for(int j=0; j<Y2.size(); j++)
      { 
        if((double)Y2[j].y-Y1[i].y<delta && (double)Y2[j].y-Y1[i].y>-delta)
          delta=min<double>(delta, distance(Y1[i], Y2[j]));
      }
    return delta;
}

double minimal_distance(vector<Point>X, vector<Point>Y) 
{
  if(X.size()==1)
  	return 1.0/0.0;
  else if(X.size()==2)
  	return (distance(X[0], X[1]));
  else
  { 
  	int i;
  	vector<Point>X1;
  	vector<Point>X2;
  	for(i=0; i<X.size()/2; i++)
  		X1.push_back(X[i]);
  	for(i=X1.size(); i<X.size(); i++)
  		X2.push_back(X[i]);
  	double delta=std::min<double>(minimal_distance(X1, Y),minimal_distance(X2, Y));
    if(delta==0)
      return 0;
    if(X1[X1.size()-1].x==X2[0].x)
    {
      for(int j=X1.size()-1; j>=0 && X1[j].x ==X2[0].x; j--)
        for(int j1=0; j1<X2.size() && X2[j1].x==X2[0].x; j1++)
        {
          if(X1[j].y==X2[j1].y)
            return 0;
        }

    }
    delta=mid_minimal_distance(X1, X2, Y, delta);
  	return delta;
  }
}

double naive_minimal_distance(vector<Point>p)
{
	double min=1.0/0.0;
	for(int i=0; i<p.size(); i++)
		for(int j=i+1; i<p.size(); j++)
			min=std::min<double>(min, distance(p[i], p[j]));
	return min;
}

int main()
{
	/*while(1)
	{
		int n=rand()%1000+2;
		std::cout<<n<<"\n";
		vector<Point>X(n);
    std::cout<<X[1].x<<"\n";
		for(int i=0; i<n; i++)
		{
			X[0].x=1;
      X[0].y=2;
		}
    std::cout<<X[0].x<<' '<<X[0].y<<' ';
    vector<Point>Y(X);
   randomized_quick_sort(X, 0, X.size()-1);
   randomized_quick_sort_y(Y, 0, Y.size()-1);
		std::cout<<X[1].x<<' '<<X[1].y<<' ';
		double res1=minimal_distance(X, Y);
		std::cout<<res1<<' ';
		double res2=naive_minimal_distance(X);
		if (res1 != res2)
		{
			std::cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
			break;
		}
		else 
    {
			std::cout << "OK\n";
		}
  }*/
  size_t n;
  std::cin >> n;
  vector<Point> X(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> X[i].x >> X[i].y;
  }
   vector<Point>Y(X);
   randomized_quick_sort(X, 0, X.size()-1);
   randomized_quick_sort_y(Y, 0, Y.size()-1);
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(X, Y) << "\n";
}