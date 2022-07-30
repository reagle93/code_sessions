#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	struct Node *left, *right;
};

int length(Node *node, int& ans) {
  
    if (node == NULL)
      return 0;

    int ls = length(node->left, ans);
    int rs = length(node->right, ans);

    int leftLen = 0, rightLen = 0;

    if (node->left && node->left->val == node->val)
      leftLen = ls + 1;

    if (node->right && node->right->val == node->val)
      rightLen = rs + 1;
     
    ans = max(ans, leftLen + rightLen);
    
    return max(leftLen, rightLen);
}

int longestSameValuePath(Node *root) {
	int ans = 0;
	length(root, ans);
	return ans;
}

Node *newNode(int data) {
  Node *temp = new Node;
  temp->val = data;
  temp->left = temp->right = NULL;
  return temp;
}

int main() {
/* Let us construct a Binary Tree
		4
	/ \
	4 4
	/ \ \
	4 9 5 */

Node *root = NULL;
root = newNode(4);
root->left = newNode(4);
root->right = newNode(4);
root->left->left = newNode(4);
root->left->right = newNode(9);
root->right->right = newNode(5);
cout << longestSameValuePath(root);
return 0;
}
