#include <bits/stdc++.h>

using namespace std;

struct Job {
	char id; 
	int dead; 
	int profit; 
};

struct sortByProfitAsc {
	bool operator()(const Job& a, const Job& b)
	{
		return (a.profit < b.profit);
	}
};

bool sortByDeadlineAsc(Job job1, Job job2) {
	return (job1.dead > job2.dead);
}

void printJobScheduling(Job arr[], int n)
{
	sort(arr, arr + n, sortByDeadlineAsc);
		
	priority_queue<Job, vector<Job>, sortByProfitAsc> pq;
	int slot_available;
	vector<Job> result;

	for (int i = 0; i < n ; i++) {
		
		if (i == n-1) {
			slot_available = arr[i].dead;
		}
		else {
			slot_available = arr[i].dead - arr[i + 1].dead;
		}

		pq.push(arr[i]);
		
		while (slot_available > 0 && pq.size() > 0) {
			
			Job job = pq.top();
			pq.pop();
			slot_available--;
			result.push_back(job);
		}
	}
	
	for (int i = 0; i < result.size(); i++)
		cout << result[i].id << ' ';
	cout << endl;
}

int main()
{
	Job arr[] = { { 'a', 2, 100 },
				{ 'b', 1, 19 },
				{ 'c', 2, 27 },
				{ 'd', 1, 25 },
				{ 'e', 3, 15 } };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Following is maximum profit sequence of jobs "
			"\n";

	printJobScheduling(arr, n);
	return 0;
}
