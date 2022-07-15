#include <iostream>
#include <string.h>
using namespace std;

int dictionaryContains(string word)
{
	string dictionary[] = {"mobile","samsung","sung","man","mango",
						"icecream","and","gok","i","like","ice","cream"};
	int size = sizeof(dictionary)/sizeof(dictionary[0]);
	for (int i = 0; i < size; i++)
		if (dictionary[i].compare(word) == 0)
		return true;
	return false;
}

bool wordBreak(string str)
{
	int size = str.size();
	bool dp[size+1];
	memset(dp, false, sizeof(dp)); 

	for (int i=1; i<=size; i++)
	{
		if (dp[i] == false && dictionaryContains( str.substr(0, i) ))
			dp[i] = true;
      
		if (dp[i] == true)
		{
			for (int j = i+1; j <= size; j++)
			{
				if (dp[j] == false && dictionaryContains( str.substr(i, j-i) ))
					dp[j] = true;
			}
		}
	}

	return dp[size];
}

int main()
{
	wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
	wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
	wordBreak("")? cout <<"Yes\n": cout << "No\n";
	wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
	wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n";
	wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n";
	return 0;
}
