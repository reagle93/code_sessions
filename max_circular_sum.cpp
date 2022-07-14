#include <bits/stdc++.h>
#include <climits>
using namespace std;

int kadane(int a[], int n)
{
	int max_so_far = INT_MIN, max_ending_here = 0;
	int i;
	for (i = 0; i < 2*n; i++) {
		max_ending_here = max_ending_here + a[i%n];
		
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;
		if (max_ending_here < 0)
			max_ending_here = 0;
	}
	return max_so_far;
}

int maxCircularSum(int a[], int n)
{
	int max_kadane = kadane(a, n);
}

int main()
{
	int a[] = { 11, 10, -20, 5, -3, -5, 8, -13, 10 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << "Maximum circular sum is " << maxCircularSum(a, n) << endl;
	return 0;
}
