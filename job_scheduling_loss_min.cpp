#include "bits/stdc++.h"
using namespace std;

int minLoss(int n, int t, int arriv[],
int units[], int prior[])
{
	int total_loss = 0;
	for (int i = 0; i < n; i++)
		total_loss += prior[i] * units[i];
	
	vector<pair<int, int> > arrivals;
	for (int i = 0; i < n; i++)
		arrivals.push_back({ arriv[i], i });
	
	sort(arrivals.begin(), arrivals.end());
	
	priority_queue<pair<int, int> > pq;
	int k = 0;
	
	for (int i = 1; i <= t; i++) {
	
		while (k < n and arrivals[k].first == i) {
			pq.push({ prior[arrivals[k].second], units[arrivals[k].second] });
			k++;
		}
		
		if (!pq.empty()) {
			auto top_priority = pq.top();
			pq.pop();
		
			total_loss -= top_priority.first;
			top_priority.second--;
			if (top_priority.second)
				pq.push(top_priority);
		}
	}

	return total_loss;
}

// driver code
int main()
{
int n = 2, t = 3;
int arriv[] = { 1, 2 };
int units[] = { 2, 2 };
int prior[] = { 100, 300 };

printf("%d\n", minLoss(n, t, arriv, units, prior));
return 0;
}
