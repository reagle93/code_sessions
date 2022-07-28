#include <bits/stdc++.h>
using namespace std;

void subsequence(char s[], char t[], int n, int k)
{
	int beg = 0, last = 0, freq = 0, j = 0;

	for (char ch = 'z'; ch >= 'a'; ch--) {
      
		freq = 0;

		for (int i = beg; i < n; i++) {
			if (s[i] == ch)
				freq++;
		}

		if (freq >= k) {

			for (int i = beg; i < n; i++) {
              
				if (s[i] == ch) {

                    t[j] = ch;
                  	j++;
					last = i;
				}
			}
            beg = last;
		}
	}
	t[k] = '\0';
}

int main()
{
	char s[] = "banana";
	int n = sizeof(s);
	int k = 2;
	char t[n];
	subsequence(s, t, n - 1, k);
	cout << t << endl;
	return 0;
}
