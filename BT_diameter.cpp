#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *left, *right;
};
struct node* newNode(int data);

pair<int, int> findDiameter(struct node* root)
{
	if (root == NULL) {
		return make_pair(0, 0);
	}

	pair<int, int> l = findDiameter(root->left);
	pair<int, int> r = findDiameter(root->right);

	int height = max(l.first, r.first) + 1;
	int diameter = max(l.first + r.first + 1, max(l.second, r.second));
  
	return make_pair(height, diameter);
}

struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	pair<int, int> res =  findDiameter(root);
	cout << "Diameter of the given binary tree is " << res.second;

	return 0;
}
