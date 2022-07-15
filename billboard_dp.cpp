#include<bits/stdc++.h>
using namespace std;

int maxRevenue(int dist[], int revenue[], int m, int n,
											int t)
{
	int maxRev[m+1];
	memset(maxRev, 0, sizeof(maxRev));

	int bbindex = 0;
	
	for (int i = 1; i <= m; i++)
	{
		if (bbindex < n)
		{
			if (dist[bbindex] != i)
				maxRev[i] = maxRev[i-1]; // no bb

			else
			{
				if (i <= t)
					maxRev[i] = max(maxRev[i-1], revenue[bbindex]); //excl, start new

				else
					maxRev[i] = max(maxRev[i-1], maxRev[i-t-1]+revenue[bbindex]); //excl, incl

				bbindex++;
			}
		}
		else
			maxRev[i] = maxRev[i - 1]; // no bb extra last miles
	}

	return maxRev[m];
}

// Driven Program
int main()
{
	int m = 20;
	int x[] = {6, 7, 12, 13, 14};
	int revenue[] = {5, 6, 5, 3, 1};
	int n = sizeof(x)/sizeof(x[0]);
	int t = 5;
	cout << maxRevenue(x, revenue, m, n, t) << endl;
	return 0;
}
