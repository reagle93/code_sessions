#include <bits/stdc++.h>
using namespace std;

void constructTree(int n, int d, int h)
{
  	if (d > 2 * h) {
		cout << "-1" << endl;
		return;
	}
  
	if (d == 1) {

      if (n == 2 && h == 1) {
			cout << "1 2" << endl;
			return;
		}
		cout << "-1" << endl; 
		return;
	}

	for (int i = 1; i <= h; i++)	
		cout << i << " " << i + 1 << endl;
	
	if (d > h) {
      
		cout << "1"<< " " << h + 2 << endl;
		for (int i = h + 2; i <= d; i++) {
			cout << i << " " << i + 1 << endl;
		}
	}
  
  	int k = (d == h)? 2 : 1;
  
  	for (int i = d + 1; i < n; i++)
  	{
   		cout << k << " " << i + 1 << endl;
  	}   
}

int main()
{
	int n = 5, d = 3, h = 2;
	constructTree(n, d, h);
	return 0;
}
