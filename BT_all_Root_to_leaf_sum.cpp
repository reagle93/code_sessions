#include <bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node *left, *right;
};

node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = Node->right = NULL;
	return (Node);
}

void treePathsSumUtil(node *root, string val, int& sum)
{
	if (root == NULL) 
		return ;

	if (root->left==NULL && root->right==NULL) {
		val += to_string(root->data);
		sum += stoi(val);
		return ;
    }

    treePathsSumUtil(root->left, val + to_string(root->data), sum);
    treePathsSumUtil(root->right, val + to_string(root->data), sum);
}

int treePathsSum(node *root)
{
	int sum = 0;
	treePathsSumUtil(root, "", sum);
	return sum;
}

int main()
{
	node *root = newNode(6);
	root->left = newNode(3);
	root->right = newNode(5);
	root->left->left = newNode(2);
	root->left->right = newNode(5);
	root->right->right = newNode(4);
	root->left->right->left = newNode(7);
	root->left->right->right = newNode(4);
	cout<<"Sum of all paths is "<<treePathsSum(root);
	return 0;
}
