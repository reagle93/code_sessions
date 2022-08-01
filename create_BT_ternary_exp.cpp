#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	Node *left, *right;
};

Node *newNode(char Data)
{
	Node *new_node = new Node;
	new_node->data = Data;
	new_node->left = new_node->right = NULL;
	return new_node;
}

Node *convertExpression(string str, int & i)
{
	Node* root = newNode(str[i]);
  	i++;

	if(i == str.length()) 
      return root;

   if(str[i]=='?') {
		i++;
     
		root->left = convertExpression(str,i);
		
		i++;

		root->right = convertExpression(str,i);
     
		return root;
	}
	else 
      return root;
}

void printTree( Node *root)
{
	if (!root)
		return ;
	cout << root->data <<" ";
	printTree(root->left);
	printTree(root->right);
}

int main()
{
	string expression = "a?b?c:d:e";
	int i=0;
	Node *root = convertExpression(expression, i);
	printTree(root) ;
	return 0;
}
