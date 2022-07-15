
#include <bits/stdc++.h>
using namespace std;

struct elem {
  int sum;
  int previous_index;
};

void constructMaxSumIS(vector<int> arr, int n)
{
	vector<elem> L(n);

	int index = 0;
  
	for (int val : arr) {
		L[index] = { val, -1 };
		index++;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]
				and L[i].sum < arr[i] + L[j].sum) {
				L[i].sum = arr[i] + L[j].sum;
				L[i].previous_index = j;
			}
		}
	}

	int max_sum = INT_MIN, max_index, i = 0;

	for (auto elem : L) {
		if (elem.sum > max_sum) {
			max_sum = elem.sum;
			max_index = i;
		}
		i++;
	}

	vector<int> result;
	int previous_index;

	while (max_index >= 0) {
		result.push_back(arr[max_index]);
		max_index = L[max_index].previous_index;
	}

	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i] << " ";
}

int main()
{
	vector<int> arr = { 1, 101, 2, 3, 100, 4, 5 };
	int n = arr.size();

	constructMaxSumIS(arr, n);

	return 0;
}
