#include<iostream>
using namespace std;

int maxSubArraySum(int a[], int size)
{
  int max_so_far = a[0];
  int curr_max = a[0];
  int start = 0;
  int end = 0;
  int curr_start = 0;

  for (int i = 1; i < size; i++)
  {
    curr_max = max(a[i], curr_max+a[i]);
    if(max_so_far < curr_max) {

      max_so_far = curr_max;
      start = curr_start;
      end = i;
    }
    if(curr_max < 0){
      curr_max = 0;
      curr_start = i + 1;
    }
  }
    cout<<"low = "<<start<<" end = "<<end;
  return max_so_far;
}

/* Driver program to test maxSubArraySum */
int main()
{
int a[] = {-2, -3, -1, -2, 0, 1, -3};
int n = sizeof(a)/sizeof(a[0]);
int max_sum = maxSubArraySum(a, n);
cout << "Maximum contiguous sum is " << max_sum;
return 0;
}
