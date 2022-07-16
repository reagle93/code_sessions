// CPP program for maximum average sum partition
#include <bits/stdc++.h>
using namespace std;

double largestSumOfAverages(vector<int>& A, int K)
{
	int n = A.size();
  
	double pre_sum[n];
	pre_sum[0] = A[0];
  
	for (int i = 1; i < n; i++)
		pre_sum[i] = pre_sum[i-1] + A[i];

	double dp[n][K] = {0};
	for (int i = 0; i < n; i++)
		dp[i][1] = (pre_sum[i]) / (i+1);
	
	for (int k = 1; k <= K; k++)
		for (int i = 1; i < n; i++)
			for (int j = 0; j < i; j++)
				dp[i][k] = max(dp[i][k], (pre_sum[i] -
						pre_sum[j]) / (i - j) + dp[j][k-1]);
	
	return dp[n-1][K];
}

// Driver code
int main()
{
	vector<int> A = { 9, 1, 2, 3, 9 };
	int K = 3; // atmost partitioning size
	cout << largestSumOfAverages(A, K) << endl;
	return 0;
}
