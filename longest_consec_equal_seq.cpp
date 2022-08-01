#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void longestConsecutiveUtil(Node* root, int curLength,
							int expected, int& res)
{
	if (root == NULL)
		return;

	if (root->data == expected)
		curLength++;
	else
		curLength = 1;

	res = max(res, curLength);

	longestConsecutiveUtil(root->left, curLength,
						root->data, res);
	longestConsecutiveUtil(root->right, curLength,
						root->data, res);
}

int longestConsecutive(Node* root)
{
	if (root == NULL)
		return 0;

	int res = 0;

	longestConsecutiveUtil(root, 0, root->data, res);

	return res;
}

int main()
{
	Node* root = newNode(6);
	root->right = newNode(9);
	root->right->left = newNode(7);
  	root->right->left->right = newNode(7);
	root->right->left->right->right = newNode(7);
	root->right->left->right->right->left = newNode(7);

	root->right->right = newNode(10);
	root->right->right->right = newNode(11);
	root->right->right->right->right = newNode(11);
  	root->right->right->right->right->right = newNode(11);


	printf("%d\n", longestConsecutive(root));
	return 0;
}
