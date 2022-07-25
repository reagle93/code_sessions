#include<bits/stdc++.h>
using namespace std;

void pushGreatestAtBack(int arr[], deque<int> &q, int i, int k) {
	while ( (!q.empty()) && arr[i] >= arr[q.back()])
		q.pop_back(); 
	q.push_back(i);
}

void pushSmallestAtBack(int arr[], deque<int> &q, int i, int k) {
	while ( (!q.empty()) && arr[i] <= arr[q.back()])
		q.pop_back();
	q.push_back(i);
}

void removeOutOfWindow(int arr[], deque<int>& q, int i, int k) {
	
	while (!q.empty() && q.front() <= i - k)
		q.pop_front();
}

int SumOfKsubArray(int arr[] , int n , int k)
{
	int sum = 0; 
	deque< int > S(k), G(k);

	int i = 0;
	for (i = 0; i < k; i++)
	{
		pushSmallestAtBack(arr, S, i, k);
		pushGreatestAtBack(arr, G, i, k);
	}

	for (i = k ; i < n; i++ )
	{
		sum += arr[S.front()] + arr[G.front()];

		removeOutOfWindow(arr, S, i, k);
		removeOutOfWindow(arr, G, i, k);

		pushSmallestAtBack(arr, S, i, k);
		pushGreatestAtBack(arr, G, i, k);
	}
	
	if(!S.empty() && !G.empty())
		sum += arr[S.front()] + arr[G.front()];

	return sum;
}

int main()
{
	int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	cout << SumOfKsubArray(arr, n, k) ;
	return 0;
}
