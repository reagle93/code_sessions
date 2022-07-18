#include<bits/stdc++.h>
using namespace std;
#define V 4

void printSolution(int color[]);

bool isSafe(bool graph[V][V], int color[])
{
	// check for every edge
	for (int i = 0; i < V; i++)
		for (int j = i + 1; j < V; j++)
			if (graph[i][j] && color[j] == color[i])
				return false;
	return true;
}

bool graphColoring(bool graph[V][V], int u,
				int color[V], int m)
{
	if (u == V) 
		return true;

	for (int j = 1; j <= m; j++) {
      
      if(isSafe(graph, color)) {
        
       	color[u] = j;
		if (graphColoring(graph, u + 1, color, m))
			return true;
		color[u] = 0;
        
      }
	}
	return false;
}

void printSolution(int color[])
{
	cout << "Solution Exists:" " Following are the assigned colors \n";
	for (int i = 0; i < V; i++)
		cout << " " << color[i];
	cout << "\n";
}

int main()
{
	bool graph[V][V] = {
		{ 0, 1, 1, 1 },
		{ 1, 0, 1, 0 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 0 },
	};
	int m = 3; 

	int color[V];
	for (int i = 0; i < V; i++)
		color[i] = 0;

	if (!graphColoring(graph, 0, color, m))
		cout << "Solution does not exist";

	return 0;
}
