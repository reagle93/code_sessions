// CPP program to minimize number of
// unique characters in a string.

#include <bits/stdc++.h>
using namespace std;

	string A = "abcc";
	string B = "aaaa";
	
void minCountUtil(string A, string B,
				unordered_map<char, int>& ele,
				int& ans, int ind)
{
	if (ind == A.length()) {
		ans = min(ans, (int)ele.size());
		return;
	}
	
    ele[B[ind]]++;
    ele[A[ind]]--;
  	if (ele[A[ind]] == 0)
		ele.erase(A[ind]);
  
	swap(A[ind], B[ind]);
	minCountUtil(A, B, ele, ans, ind + 1);
  
  	swap(A[ind], B[ind]);

    ele[A[ind]]++;
    ele[B[ind]]--;
  	if (ele[B[ind]] == 0)
		ele.erase(B[ind]);
  
	minCountUtil(A, B, ele, ans, ind + 1);
	return ;
}

int minCount(string A, string B)
{
	int ans = A.length();
	unordered_map<char, int> ele;
	for(auto elem: A)
		ele[elem]++;
		
	minCountUtil(A, B, ele, ans, 0);

	return ans;
}

int main()
{
	string A = "abcc";
	string B = "baaa";

	cout << minCount(A, B);
	return 0;
}
