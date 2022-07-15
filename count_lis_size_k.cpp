#include <bits/stdc++.h>
using namespace std;

int numOfIncSubseqOfSizeK(int arr[], int n, int k)
{
	int dp[k+1][n], sum = 0;
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < n; i++)
		dp[1][i] = 1;

	for (int len = 2; len <= k; len++) {
      
		for (int i = len -1 ; i < n; i++) { // seq starts from len -1 for > for seq of length len

			dp[len][i] = 0;
			for (int j = len - 2; j < i; j++) { // index of previous elem
				if (arr[j] < arr[i])
					dp[len][i] += dp[len - 1][j];
			}
		}
	}

	for (int i = k - 1; i < n; i++)
		sum += dp[k][i];

	return sum;
}

int main()
{
	int arr[] = { 12, 8, 11, 13, 10, 15, 14, 16, 20, 23 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 4;

	cout << "Number of Increasing Subsequences of size "
		<< k << " = " << numOfIncSubseqOfSizeK(arr, n, k);

	return 0;
}
