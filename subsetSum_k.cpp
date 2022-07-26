#include <iostream>
#include <numeric>
#include <algorithm> 
#include <cstring>
using namespace std;

void printSubset(int arr[], int n) {
	
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
}

void util(int arr[], int index1, int subset[], int index2, int n, int curr_sum, int target) {
	
	if(index1 > n || index2 > n || curr_sum > target)
		return ;
		
	if(curr_sum == target) {
		printSubset(subset, index2);
		return ;
	}
	
	subset[index2] = arr[index1];
	util(arr, index1 + 1, subset, index2 + 1, n, curr_sum + arr[index1], target);
	
	util(arr, index1 + 1, subset, index2, n, curr_sum, target);
	
}

void generateSubset(int arr[], int n, int target) {
	
	int sum = accumulate(arr, arr+n, 0);
	
	if(target > sum)
		return ;
		
	sort(arr, arr+n);
	
	int subset[n];
	memset(subset, n, 0);
	
	util(arr, 0, subset, 0, n, 0, target);
}

int main() {
	int arr[] = {15, 22, 14, 26, 32, 9, 16, 8};
	int target = 53;
	
	generateSubset(arr, 8, target);
	return 0;
}
