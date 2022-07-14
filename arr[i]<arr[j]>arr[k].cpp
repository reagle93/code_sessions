
#include <bits/stdc++.h>
using namespace std;

void find3Numbers(vector<int>& nums)
{
	
  if (nums.size() < 3){
      cout << "No such triplet found";
      return;
  }

  int seq_max_val = INT_MAX;	
  int seq_min_val = nums[0];
  int min_num = nums[0];

  for (int i = 1; i < nums.size(); i++)
  {
      if (nums[i] < min_num) {
          min_num = nums[i];
      }
      else if(nums[i] > min_num) {
        
          if (nums[i] > seq_max_val)
          {	
            seq_max_val = nums[i];	// seq_max_val as high as possible
            seq_min_val = min_num;	// working min	
          }
        
          else if (nums[i] < seq_max_val) {
              cout << "Triplet: " << seq_min_val <<", " << seq_max_val << ", " <<nums[i] << endl;
              return;
          }
      } 
  }
  cout << "No such triplet found";
}

int main() {
  vector<int> nums {1,2,-1,7,5};
  find3Numbers(nums);
}
