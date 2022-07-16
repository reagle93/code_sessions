
#include<bits/stdc++.h>
using namespace std;
int lookup[50][1000][1000][2];

int countRec(int index, int esum, int osum, bool isOdd, int n)
{
	if (index == n)
		return (esum - osum == 1);

	if (lookup[index][esum][osum][isOdd] != -1)
		return lookup[index][esum][osum][isOdd];

	int ans = 0;

	if (isOdd)
		for (int i = 0; i <= 9; i++)
			ans += countRec(index+1, esum, osum+i, false, n);
	else 
		for (int i = 0; i <= 9; i++)
			ans += countRec(index+1, esum+i, osum, true, n);

	return lookup[index][esum][osum][isOdd] = ans;
}

int finalCount(int n)
{
	memset(lookup, -1, sizeof lookup);
	int ans = 0;
	int esum = 0, osum = 0;

	for (int i = 1; i <= 9; i++)
		ans += countRec(1, esum + i, osum, true, n);

	return ans;
}

// Driver program
int main()
{
	int n = 3;
	cout << "Count of "<<n << " digit numbers is " << finalCount(n);
	return 0;
}
