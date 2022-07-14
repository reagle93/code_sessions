
#include <bits/stdc++.h>
using namespace std;

bool modularSum(int arr[], int n, int m)
{
	if (n > m)
		return true;

	bool dp[m];
	memset(dp, false, m);

	for (int i=0; i<n; i++)
	{
    if (dp[0])
			break;
      
		bool temp[m];
		memset(temp, false, m);

		for (int j=0; j<m; j++)
		{
			if (dp[j] == true)
				temp[(j+arr[i]) % m] = true;		
		}

		for (int j=0; j<m; j++)
			if (temp[j])
				dp[j] = true;
      
		dp[arr[i]%m] = true;
	}

	return dp[0];
}

int main()
{
	int arr[] = {1, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	int m = 5;

	modularSum(arr, n, m) ? cout << "YES\n" :
							cout << "NO\n";

	return 0;
}
