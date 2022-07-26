#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool isSafe(vector<vector<int>> &mat, vector<vector<bool>> &visited, int x, int y)
{
    return (x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size()) &&
            mat[x][y] == 1 && !visited[x][y];
}

int xx[4] = {-1, 0, 0, 1};
int yy[4] = {0, 1, -1, 0};
 
void findLongestPath(vector<vector<int>> &mat, vector<vector<bool>> &visited,
                int i, int j, int x, int y, int &max_dist, int dist)
{
    if (mat[i][j] == 0) {
        return;
    }
 
    if (i == x && j == y)
    {
        max_dist = max(dist, max_dist);
        return;
    }
 
    visited[i][j] = 1;
 
	for(int k =0; k<4; k++) {
		if (isSafe(mat, visited, i + xx[k], j + yy[k])) {
	        findLongestPath(mat, visited, i + xx[k], j + yy[k], x, y, max_dist, dist + 1);
	    }
	}
	
    visited[i][j] = 0;
}
 
int findLongestPathLength(vector<vector<int>> &mat, pair<int, int> &src,
                    pair<int, int> &dest)
{
    if (mat.size() == 0 || mat[src.first][src.second] == 0 ||
            mat[dest.first][dest.second] == 0) {
        return -1;
    }
 
    int M = mat.size();
    int N = mat[0].size();
 
    vector<vector<bool>> visited;
    visited.resize(M, vector<bool>(N));
 
    int max_dist = 0;
    findLongestPath(mat, visited, src.first, src.second, dest.first, dest.second,
            max_dist, 0);
 
    return max_dist;
}
 
int main()
{
    vector<vector<int>> mat =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
        { 1, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }
    };
 
    pair<int, int> src = make_pair(0, 0);
    pair<int, int> dest = make_pair(5, 7);
 
    cout << "The Maximum length path is " << findLongestPathLength(mat, src, dest);
 
    return 0;
}
