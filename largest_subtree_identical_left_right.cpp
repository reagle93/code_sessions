// C++ program to find the largest subtree
// having identical left and right subtree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
struct Node
{
	int data;
	Node* left, * right;
};

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

int largestSubtreeUtil(Node* root, string& str,
					int& maxSize, Node*& maxNode)
{
	if (root == NULL)
		return 0;

	string left = "", right = "";

	int ls = largestSubtreeUtil(root->left, left, maxSize, maxNode);

	int rs = largestSubtreeUtil(root->right, right, maxSize, maxNode);


	int size = ls + rs + 1;
	
	if (left.compare(right) == 0)
	{
		if (size > maxSize)
		{
			maxSize = size;
			maxNode = root;
		}
	}

	str.append("|").append(left).append("|");

	str.append(to_string(root->data));

	str.append("|").append(right).append("|");

	return size;
}

int largestSubtree(Node* node, Node*& maxNode)
{
	int maxSize = 0;
	string str = "";
	largestSubtreeUtil(node, str, maxSize, maxNode);

	return maxSize;
}

int main()
{
	/* Let us construct the following Tree
				50
			/	 \
			10	 60
			/ \	 / \
			5 20 70 70
				/ \ / \
				65 80 65 80 */
	Node* root = newNode(50);
	root->left = newNode(10);
	root->right = newNode(60);
	root->left->left = newNode(5);
	root->left->right = newNode(20);
	root->right->left = newNode(70);
	root->right->left->left = newNode(65);
	root->right->left->right = newNode(80);
	root->right->right = newNode(70);
	root->right->right->left = newNode(65);
	root->right->right->right = newNode(80);

	Node *maxNode = NULL;
	int maxSize = largestSubtree(root, maxNode);

	cout << "Largest Subtree is rooted at node "
		<< maxNode->data << "\nand its size is "
		<< maxSize;

	return 0;
}
