// C++ program to print matrix in anti-spiral form
#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 5

void antiSpiralTraversal(int m, int n, int a[R][C])
{
	int i, k = 0, l = 0;

	/* k - starting row index
		m - ending row index
		l - starting column index
		n - ending column index
		i - iterator */
	stack<int> stk;

	while (k <= m && l <= n)
	{
		/* Print the first row from the remaining rows */
		for (i = l; i <= n; ++i)
			stk.push(a[k][i]);
		k++;

		/* Print the last column from the remaining columns */
		for (i = k; i <= m; ++i)
			stk.push(a[i][n]);
		n--;

		/* Print the last row from the remaining rows */
		if ( k <= m)
		{
			for (i = n; i >= l; --i)
				stk.push(a[m][i]);
			m--;
		}

		/* Print the first column from the remaining columns */
		if (l <= n)
		{
			for (i = m; i >= k; --i)
				stk.push(a[i][l]);
			l++;
		}
	}

	while (!stk.empty())
	{
		cout << stk.top() << " ";
		stk.pop();
	}
}

/* Driver program to test above functions */
int main()
{
	int mat[R][C] =
	{
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20}
	};

	antiSpiralTraversal(R-1, C-1, mat);

	return 0;
}
