#include <bits/stdc++.h>
using namespace std;

# define N 6

struct Node
{
	int data;
	Node *left, *right;
};

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

Node* ancestorTree(int mat[][N])
{
	bool hasParent[N] = {false};

	Node* root = NULL;

	multimap<int, int> mm;

	for (int i = 0; i < N; i++)
	{
		int sum = 0; 
		for (int j = 0; j < N; j++)
			sum += mat[i][j];

		mm.insert(pair<int, int>(sum, i));
	}

	Node* node[N];

	for (auto it = mm.begin(); it != mm.end(); ++it) // process child first before parent
	{
		auto current_node = it->second;
		node[current_node] = newNode(current_node);
	
		root = node[current_node];
		
		int child_count = it->first;
	
		if ( child_count != 0) {
			
			for (int i = 0; i < N; i++) { // child nodes,
				
				if (hasParent[i] == false && mat[current_node][i]) { // i is child with no parent
					
					if (root->left == NULL)
						root->left = node[i];
					else
						root->right = node[i];
		
					hasParent[i] = true;
				}
			}
		}
	}
	return root;
}

void printInorder(Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
}

int main()
{
	int mat[N][N] = {{ 0, 0, 0, 0, 0, 0 },
		{ 1, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 0 }
	};

	Node* root = ancestorTree(mat);

	cout << "Inorder traversal of tree is \n";
	
	printInorder(root);

	return 0;
}
