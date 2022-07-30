#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

vector<int> adj[MAX];

int build_tree(int arr[], int n)
{
	int root_index = 0;

	for (int i = 0; i < n; i++) {

		if (arr[i] == -1)
			root_index = i;

		else {
			adj[i].push_back(arr[i]);
			adj[arr[i]].push_back(i);
		}
	}
	return root_index;
}

int BFS(int start)
{
	map<int, bool> vis;
	queue<pair<int, int> > q;
	int max_level_reached = 0;

	q.push({ start, 0 });

	pair<int, int> p;

	while (!q.empty()) {

		p = q.front();
      	q.pop();
      
		vis[p.first] = true;
		max_level_reached = max(max_level_reached, p.second);

		for (int i = 0; i < adj[p.first].size(); i++)

			if (!vis[adj[p.first][i]])
				q.push({ adj[p.first][i], p.second + 1 });
	}
	return max_level_reached;
}

int main()
{
	int parent[] = { -1, 0, 1, 2, 3 };

	int n = sizeof(parent) / sizeof(parent[0]);

	int root_index = build_tree(parent, n);

	int ma = BFS(root_index);
	cout << "Height of N-ary Tree=" << ma;
	return 0;
}
