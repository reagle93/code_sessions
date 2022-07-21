// CPP program to minimize number of
// unique characters in a string.

#include <bits/stdc++.h>
using namespace std;

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
  
    ele[A[ind]]++;
    ele[B[ind]]--;
  	if (ele[B[ind]] == 0)
		ele.erase(B[ind]);
  
	swap(A[ind], B[ind]);
	minCountUtil(A, B, ele, ans, ind + 1);
}

int minCount(string A, string B)
{
	int ans = A.length();
	unordered_map<char, int> ele;

	minCountUtil(A, B, ele, ans, 0);

	return ans;
}

int main()
{
	string A = "bfaaabbbbdbabababeba";
	string B = "bbabbbbababababbbbde";

	cout << minCount(A, B);
	return 0;
}
