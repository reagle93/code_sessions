#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

Node *newNode(int data)
{
	Node *node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void maxSumPathUtil(Node *root, int sum, int& max_sum)
{
	if (root == NULL)
		return ;

	maxSumPathUtil(root->left, sum + root->data, max_sum);
	maxSumPathUtil(root->right, sum + root->data, max_sum);

	if (root->left == NULL && root->right == NULL && sum + root->data > max_sum)
	{
		max_sum = sum + root->data;
	}
	return ;
}

int maxSumPath(Node *root)
{
	int sum = 0;
	maxSumPathUtil(root, 0, sum);
	return sum;
}

void printInorder(Node *root)
{
	if (root)
	{
		printInorder(root->left);
		cout << root->data << " ";
		printInorder(root->right);
	}
}

int main() {
	Node* root = NULL;
  
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
  
    cout << "Following are the nodes on the maximum "
            "sum path \n";
    int sum = maxSumPath(root);
    cout << "\nSum of the nodes is " << sum;
	return 0;
}
