#include <bits/stdc++.h>
using namespace std;

void TOWUtil(int* arr, int n, vector<bool>&curr_elements, int no_of_selected_elements,
			vector<bool>&soln, int&min_diff, int sum, int curr_sum, int index)
{
	if (index == n)
		return;

	if (n/2 - no_of_selected_elements > n - index)
		return;
  
  	if (no_of_selected_elements == n/2)
	{
		if (abs(sum/2 - curr_sum) < min_diff)
		{
			min_diff = abs(sum/2 - curr_sum);
			for (int i = 0; i<n; i++)
				soln[i] = curr_elements[i];
		}
	}
  
  	no_of_selected_elements++;
	curr_sum = curr_sum + arr[index];
	curr_elements[index] = true;

	TOWUtil(arr, n, curr_elements, no_of_selected_elements,
			soln, min_diff, sum, curr_sum, index+1);
  
    no_of_selected_elements--;
	curr_sum = curr_sum - arr[index];
	curr_elements[index] = false;

	TOWUtil(arr, n, curr_elements, no_of_selected_elements, soln,
				min_diff, sum, curr_sum, index+1);
}

// main function that generate an arr
void tugOfWar(int *arr, int n)
{
	vector<bool> curr_elements(n, false);
    vector<bool> soln(n, false);

	int min_diff = INT_MAX;

	int sum = 0;
	for (int i=0; i<n; i++)
	{
		sum += arr[i];
		curr_elements[i] = soln[i] = false;
	}

	TOWUtil(arr, n, curr_elements, 0, soln, min_diff, sum, 0, 0);

	cout << "The first subset is: ";
	for (int i=0; i<n; i++)
	{
		if (soln[i] == true)
			cout << arr[i] << " ";
	}
	cout << "\nThe second subset is: ";
	for (int i=0; i<n; i++)
	{
		if (soln[i] == false)
			cout << arr[i] << " ";
	}
}

int main()
{
	int arr[] = {23, 44, -34, 12, 0, 94, -99, 4, 189, 0, 8};
	int n = sizeof(arr)/sizeof(arr[0]);
	tugOfWar(arr, n);
	return 0;
}
