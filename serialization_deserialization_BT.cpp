/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    
    void util(TreeNode* root, string& encode) {
        
        if(root == NULL) 
            return ;
        
        encode += to_string(root->val);
        
        if(root->left == NULL && root->right == NULL)
            return ;
        
        encode += '(';
        util(root->left, encode);
        encode += ')';

        if(root->right) {
            encode += '(';
            util(root->right, encode);
            encode += ')';
        }
    }
    
    
    string serialize(TreeNode* root) {
        
        string encode = "";     
        util(root, encode);
        return encode;
    }
    
    TreeNode* constructtree(string s, int& start)
    {
        if (s.size() == 0 || start >= s.size())
            return NULL;

        int num = 0;
        int neg = 1;
        bool flag = false;
        
        if(start < s.size() && s[start] == '-') {
          neg = -1;
          start = start +1;
        }

        while (start < s.size() && s[start] != '(' && s[start] != ')') {
            int num_here = (int)(s[start] - '0');
            num = num * 10 + num_here;
            start = start + 1;
            flag = true;
        }

        num*= neg;

        TreeNode* root = NULL;
        if(flag)
            root = new TreeNode(num); // to avoid empty bracktes '()'

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

    TreeNode* deserialize(string data) {
        
        int start = 0;
        return constructtree(data, start);  
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
