#include<bits/stdc++.h>

using namespace std;

struct node
{
int data;
struct node* left;
struct node* right;
};

bool printAncestors(struct node *root, int target, int& k)
{
  if (root == NULL)
      return false;

  if (root->data == target)
      return true;

  if ( printAncestors(root->left, target, k) ||
      printAncestors(root->right, target, k) )
  {
      k--;

      if(k == 0)
          cout << root->data << " ";
      return true;
  }
  return false;
}

struct node* newnode(int data)
{
  struct node* node = (struct node*)
            malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

int main()
{

/* Construct the following binary tree
			1
			/ \
		2	 3
		/ \
	4	 5
	/
	7
*/
struct node *root = newnode(1);
root->left	 = newnode(2);
root->right	 = newnode(3);
root->left->left = newnode(4);
root->left->right = newnode(5);
root->left->left->left = newnode(7);

  int k = 3;
printAncestors(root, 7, k);

getchar();
return 0;
}
