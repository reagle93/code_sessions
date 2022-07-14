#include <bits/stdc++.h>
using namespace std;

int maxSubarrayProduct(int arr[], int n)
{
	int curr_max_product = 1;
	int curr_min_product = 1;
	int max_so_far = 0;
  
	for (int i = 0; i < n; i++)
	{ 
      	if (arr[i] == 0) {
			curr_max_product = 1;
			curr_min_product = 1;
		}
      
		else if (arr[i] > 0)
		{
			curr_max_product = curr_max_product * arr[i];
			curr_min_product
				= min(curr_min_product * arr[i], 1);
		}

		else {
			int temp = curr_max_product;
			curr_max_product
				= max(curr_min_product * arr[i], 1);
			curr_min_product = temp * arr[i];
		}

		if (max_so_far < curr_max_product)
			max_so_far = curr_max_product;
	}

  	if (max_so_far < 0) // All Negative
	{
      max_so_far = arr[0];
      for(int i = 1; i < n; i++)
          max_so_far = max(max_so_far, arr[i]);
  }
	return max_so_far;
}

// Driver code
int main()
{
	int arr[] = { 1, -2, -3, 0, 7, -8, -2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum Sub array product is "
		<< maxSubarrayProduct(arr, n);
	return 0;
}

// This is code is contributed by rathbhupendra
