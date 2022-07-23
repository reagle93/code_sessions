#include <iostream>
#include <deque>
#include <map>
using namespace std;
#define C 3

void zigZagMatrix(int arr[][C], int n, int m)
{
	map<int, deque<int>> mp;
	
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			int sum = i+j;
			if((i+j)%2 == 0)
				mp[sum].push_front(arr[i][j]);
			else
				mp[sum].push_back(arr[i][j]);
		}
	}
	
	for(auto dQit: mp) {
		deque<int> q = dQit.second;
		for(auto it = q.begin(); it != q.end(); it++)
			cout<<*it<<" ";
	}
}

int main()
{
	int matrix[][3] = { { 1, 2, 3 },
						{ 4, 5, 6 },
						{ 7, 8, 9 } };
	zigZagMatrix(matrix, 3, 3);

	return 0;
}
