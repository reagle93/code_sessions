#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left;
	node* right;
	node *nextRight;
	
	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->nextRight = NULL;
	}
};

void connectRecur(struct node* p);
struct node *getNextRight(struct node *p);

void connect (struct node *p)
{
	p->nextRight = NULL;
	connectRecur(p);
}

void connectRecur(struct node* p)
{
	if (p == NULL)
	return;

	if (p->nextRight)
		connectRecur(p->nextRight);

	if (p->left)
	{
		if (p->right)
			p->left->nextRight = p->right;
		else
			p->left->nextRight = getNextRight(p);
		connectRecur(p->left);
	}
	if (p->right)
	{
		p->right->nextRight = getNextRight(p);
		connectRecur(p->right);
	}
	else
		connectRecur(getNextRight(p));
}

struct node *getNextRight(struct node *p)
{
	struct node *temp = p->nextRight;
	
	while(temp != NULL)
	{
		if(temp->left != NULL)
			return temp->left;
		if(temp->right != NULL)
			return temp->right;
		temp = temp->nextRight;
	}
	return NULL;
}

int main()
{

	/* Constructed binary tree is
			10
			/ \
		8 2
		/	 \
	3	 90
	*/
	node *root = new node(10);
	root->left = new node(8);
	root->right = new node(2);
	root->left->left = new node(3);
	root->right->right	 = new node(90);

	connectRecur(root);

	cout << "Following are populated nextRight pointers in the tree"
		" (-1 is printed if there is no nextRight) \n";
	cout << "nextRight of " << root->data << " is "
		<< (root->nextRight? root->nextRight->data: -1) <<endl;
	cout << "nextRight of " << root->left->data << " is "
		<< (root->left->nextRight? root->left->nextRight->data: -1) << endl;
	cout << "nextRight of " << root->right->data << " is "
		<< (root->right->nextRight? root->right->nextRight->data: -1) << endl;
	cout << "nextRight of " << root->left->left->data<< " is "
		<< (root->left->left->nextRight? root->left->left->nextRight->data: -1) << endl;
	cout << "nextRight of " << root->right->right->data << " is "
		<< (root->right->right->nextRight? root->right->right->nextRight->data: -1) << endl;
	return 0;
}
