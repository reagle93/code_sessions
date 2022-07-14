#include <bits/stdc++.h>
using namespace std;

int countSubsequences(string s)
{
	int aCount = 0;
	int abCount = 0;
	int abcCount = 0;

	for (int i = 0; i < s.size(); i++) {

		if (s[i] == 'a')
			aCount = (1 + 2 * aCount);

		else if (s[i] == 'b')
			abCount = (aCount + 2 * abCount);

		else if (s[i] == 'c')
			abcCount = (abCount + 2 * abcCount);
	}

	return abcCount;
}

int main()
{
	string s = "abbc";
	cout << countSubsequences(s) << endl;
	return 0;
}
