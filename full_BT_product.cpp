
#include<bits/stdc++.h>
using namespace std;

int numoffbt(int arr[], int n)
{
	int maxvalue = INT_MIN, minvalue = INT_MAX;
  
	for (int i = 0; i < n; i++)
	{
		maxvalue = max(maxvalue, arr[i]);
		minvalue = min(minvalue, arr[i]);
	}

	bool visited[maxvalue + 2];
	int value[maxvalue + 2];
  
	memset(visited, false, sizeof(mark));
	memset(value, 0, sizeof(value));

	for (int i = 0; i < n; i++)
	{
		visited[arr[i]] = true;
		value[arr[i]] = 1;
	}

	int ans = 0;
	for (int i = minvalue; i <= maxvalue; i++)
	{
		if (visited[i]) {

			for (int j = i + i; j <= maxvalue && j/i <= i; j += i) {

				if (visited[j] == false)
					continue;

				value[j] += (value[i] * value[j/i]);

				if (i != j/i)
					value[j] += (value[i] * value[j/i]);
			}
		}
		ans += value[i];
	}
	return ans;
}

int main()
{
	int arr[] = { 2, 3, 4, 6 };
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << numoffbt(arr, n) << endl;
	return 0;
}
