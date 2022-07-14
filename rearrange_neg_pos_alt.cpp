/* C++ program to rearrange
positive and negative integers
in alternate fashion while keeping
the order of positive and negative numbers. */
#include <assert.h>
#include <iostream>
using namespace std;

// Utility function to right rotate all elements between
// [outofplace, cur]
void rightrotate(int arr[], int n, int outofplaceIndex, int cur)
{
	char tmp = arr[cur];
	for (int i = cur; i > outofplaceIndex; i--)
		arr[i] = arr[i - 1];
	arr[outofplaceIndex] = tmp;
}

bool canRotateFix(int current, int outofPlace) {
  
  return ((current >= 0 && outofPlace < 0)
				|| (current < 0 && outofPlace >= 0));
}

bool isOutOfPlace(int current, int index) {
  
  return ((current >= 0 && index%2 != 0)
				|| (current < 0  && index%2 == 0));
}

void rearrange(int arr[], int n)
{
	int outofplaceIndex = -1;

	for (int i = 0; i < n; i++)
	{
		if (outofplaceIndex >= 0)
		{
			if (canRotateFix(arr[i], arr[outofplaceIndex]))
			{
				rightrotate(arr, n, outofplaceIndex, i);

				if (i - outofplaceIndex >= 2)
					outofplaceIndex = outofplaceIndex + 2;
				else
					outofplaceIndex = -1;
			}
		}
		if (outofplaceIndex == -1 && isOutOfPlace(arr[i], i)) {
				outofplaceIndex = i;
		}
	}
}

// A utility function to print an array 'arr[]' of size 'n'
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
	
	int arr[] = { -2, 3, 4, 5, -6, -7, -8, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, n);

	rearrange(arr, n);

	cout << "Rearranged array is \n";
	printArray(arr, n);

	return 0;
}
