#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val)
	{
		data = val;
		left = right = NULL;
	}
};

Node* constructtree(string s, int& start)
{
	if (s.size() == 0 || start >= s.size())
		return NULL;

	int num = 0;
  int neg = 1;
  
  if(start < s.size() && s[start] == '-') {
      neg = -1;
      start = start +1;
  }
  
	while (start < s.size() && s[start] != '(' && s[start] != ')') {
		int num_here = (int)(s[start] - '0');
		num = num * 10 + num_here;
		start = start + 1;
	}
	
  num*= neg;

	struct Node* root = NULL;
	root = new Node(num);

	if (start < s.size() && s[start] == '(') {
		start = start + 1;
		root->left = constructtree(s, start);
	}
	if (start < s.size() && s[start] == ')') {
        start = start + 1;
        return root;
	}

	if (start < s.size() && s[start] == '(') {
		start = start + 1;
		root->right = constructtree(s, start);
	}
	if (start < s.size() && s[start] == ')')
		start = start + 1;
	return root;
}

void preorder(Node* root)
{
	if (root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

int main()
{
	string s = "4(2(-31)(1))(62(-5))";
	// cin>>s;
	int start = 0;
	Node* root = constructtree(s, start);
	preorder(root);
	return 0;
}
//This code is contributed by Chaitanya Sharma.
