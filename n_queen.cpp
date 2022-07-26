#include <bits/stdc++.h>

#define breakLine cout << "\n---------------------------------\n";
#define MAX 10

using namespace std;

int arr[MAX], no;

void nQueens(int k, int n);
bool canPlace(int k, int i);
void display(int n);

void nQueens(int col, int n){

	for (int i = 1;i <= n;i++){
		if (canPlace(col, i)){
			arr[col] = i;
			if (col == n)
				display(n);
			else
				nQueens(col + 1, n);
		}
	}
}

bool canPlace(int col, int row){
	for (int j = 1;j <= col - 1;j++){
		if (arr[j] == row ||
			(abs(arr[j] - row) == abs(j - col))) //same row or diagnonal
		return false;
	}
	return true;
}

void display(int n){
	breakLine
	cout << "Arrangement No. " << ++no;
	breakLine

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (arr[i] != j)
				cout << "\t_";
			else
				cout << "\tQ";
		}
		cout << endl;
	}

	breakLine
}

// Driver Code
int main(){
	int n = 4;
	nQueens(1, n);
	return 0;
}
