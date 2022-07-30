#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int d)
	{
		data = d;
		left = right = NULL;
	}
};

pair<int, bool> isBalanced(Node* root)
{  
	if (root == NULL) {
		return make_pair(0, true);
	}
    
	pair<int, bool> l = isBalanced(root->left);
	pair<int, bool> r = isBalanced(root->right);

	int height = max(l.first, r.first) + 1;
	int isBalance = (abs(l.first - r.first) >= 2)? false : (l.second && r.second);
	
  	return make_pair(height, isBalance);
}

int main()
{
	int height = 0;
	
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->left->left->left = new Node(7);

	
  	pair<int, bool> res = isBalanced(root);
  
	if (res.second)
		cout << "Tree is balanced";
	else
		cout << "Tree is not balanced";

	return 0;
}
