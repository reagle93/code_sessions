#include <bits/stdc++.h>
using namespace std;

void pushGreatestAtBack(int arr[], deque<int>& q, int i, int k) {
	
	while ((!q.empty()) && arr[i] >= arr[q.back()]) {
		q.pop_back();
	}
	q.push_back(i);
}

void removeOutOfWindow(int arr[], deque<int>& q, int i, int k) {
	
	while (!q.empty() && q.front() <= i - k)
	q.pop_front();
}

void printKMax(int arr[], int n, int k)
{
	deque<int> q(k);

	for (int i = 0; i < k; ++i)
	{
		pushGreatestAtBack(arr, q, i, k);
	}

	for (int i = k; i < n; ++i)
	{
		cout << arr[q.front()] << " ";
		removeOutOfWindow(arr, q, i, k);
		pushGreatestAtBack(arr, q, i, k);
	}
	cout << arr[q.front()];
}

int main()
{
	int arr[] = { 12, 1, 78, 90, 57, 89, 56 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	printKMax(arr, n, k);
	return 0;
}
