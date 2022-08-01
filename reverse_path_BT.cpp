#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

Node* reverseTreePathUtil(Node* root, int data, map<int, int>& path, int level, int& index)
{
	if (root == NULL)
		return NULL;

	if (root->data == data) {

		path[level] = root->data;

		root->data = path[index];

		index++;
		return root;
	}

	path[level] = root->data;

	Node *left, *right;
	
	left = reverseTreePathUtil(root->left, data, path, level + 1, index);
	
	if (left == NULL)
		right = reverseTreePathUtil(root->right, data, path, level + 1, index);

	if (left || right) {
		
		root->data = path[index];
		index++;
		return (left ? left : right);
	}
	return NULL;
}

void reverseTreePath(Node* root, int data)
{
	map<int, int> path;

	int index = 0;

	reverseTreePathUtil(root, data, path, 0, index);
}

void inorder(Node* root)
{
	if (root != NULL) {
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int main()
{
	Node* root = newNode(7);
	root->left = newNode(6);
	root->right = newNode(5);
	root->left->left = newNode(4);
	root->left->right = newNode(3);
	root->right->left = newNode(2);
	root->right->right = newNode(1);

	/*	 7
		/ \
		6	 5
	/ \	 / \
	4 3	 2 1		 */

	int data = 4;

	reverseTreePath(root, data);

	inorder(root);
	return 0;
}
