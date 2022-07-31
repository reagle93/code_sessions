#include<bits/stdc++.h>
using namespace std;

int numoffbt(int arr[], int n)
{
int maxvalue = *max_element(arr, arr+n);

set<int> visited(arr, arr+n);

int treeCount[maxvalue + 2];
memset(treeCount, 0, sizeof(treeCount));

for (int i = 0; i < n; i++)
{
	visited.insert(arr[i]);
	treeCount[arr[i]] = 1;
}

int ans = 0;

for (int i = 0; i < n; i++) {	

      for (int j = arr[i] + arr[i]; j <= maxvalue && j/arr[i] <= arr[i]; j += arr[i]) {

	    if (visited.find(j) != visited.end()) {

		treeCount[j] = treeCount[j] + (treeCount[arr[i]] * treeCount[j/arr[i]]);

	      if (arr[i] != j/arr[i])
		treeCount[j] = treeCount[j] + (treeCount[arr[i]] * treeCount[j/arr[i]]);
	    }
	}  
ans += treeCount[arr[i]];
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
