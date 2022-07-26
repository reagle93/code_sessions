#include <bits/stdc++.h>
using namespace std;

bool isKPartitionPossibleRec(int arr[], int subsetSum[], bool taken[],
				int target, int K, int N, int curIdx, int limitIdx)
{
	if (subsetSum[curIdx] == target)
	{
		if (curIdx == K - 2)
			return true;

      return isKPartitionPossibleRec(arr, subsetSum, taken, target,
											K, N, curIdx + 1, N - 1);
	}

	for (int i = limitIdx; i >= 0; i--)
	{
		if (taken[i])
			continue;
		int tmp = subsetSum[curIdx] + arr[i];

		if (tmp <= target)
		{
			taken[i] = true;
			subsetSum[curIdx] += arr[i];
			if(isKPartitionPossibleRec(arr, subsetSum, taken,
											target, K, N, curIdx, i - 1))
				return true;


			taken[i] = false;
			subsetSum[curIdx] -= arr[i];
		}
	}
	return false;
}

// Method returns true if arr can be partitioned into K subsets
// with equal sum
bool isKPartitionPossible(int arr[], int N, int K)
{
	if (K == 1)
		return true;

	if (N < K)
		return false;

	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += arr[i];
	if (sum % K != 0)
		return false;

	int target = sum / K;
	int subsetSum[K];
	bool taken[N];

	for (int i = 0; i < K; i++)
		subsetSum[i] = 0;

	for (int i = 0; i < N; i++)
		taken[i] = false;

	subsetSum[0] = arr[N - 1];
	taken[N - 1] = true;

	return isKPartitionPossibleRec(arr, subsetSum, taken,
									target, K, N, 0, N - 1);
}

// Driver code to test above methods
int main()
{
	int arr[] = {2, 1, 4, 5, 3, 3};
	int N = sizeof(arr) / sizeof(arr[0]);
	int K = 3;

	if (isKPartitionPossible(arr, N, K))
		cout << "Partitions into equal sum is possible.\n";
	else
		cout << "Partitions into equal sum is not possible.\n";
}
