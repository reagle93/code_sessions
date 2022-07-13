// C++ program for space optimized
// solution of Word Wrap problem.

#include <bits/stdc++.h>
using namespace std;

// Function to find space optimized
// solution of Word Wrap problem.
void solveWordWrap(int wordLen[], int n, int k)
{
	int i, j;
	int currlen;
	int current_cost;
	int costStartIndex[n];
	int endIndex[n];
  
	costStartIndex[n - 1] = 0;
	endIndex[n - 1] = n - 1;

	for (i = n - 2; i >= 0; i--) {
      
		currlen = -1;
		costStartIndex[i] = INT_MAX;

		for (j = i; j < n; j++) {

			currlen += (wordLen[j] + 1);

			if (currlen > k)
				break;

			if (j == n - 1)
				current_cost = 0;
			else
				current_cost = (k - currlen) * (k - currlen) + costStartIndex[j + 1];

			if (current_cost < costStartIndex[i]) {
				costStartIndex[i] = cost;
				endIndex[i] = j;
			}
		}
	}

	i = 0;
	while (i < n) {
		cout << i + 1 << " " << endIndex[i] + 1 << " ";
		i = endIndex[i] + 1;
	}
}

// Driver function
int main()
{
	int arr[] = { 3, 2, 2, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int M = 6;
	solveWordWrap(arr, n, M);
	return 0;
}
