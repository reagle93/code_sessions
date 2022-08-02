   int util(TreeNode* root, int expected, int& max_len) {
        
        if(root == NULL)
            return 0;
       
       int ls = util(root->left, root->val, max_len);
       int rs = util(root->right, root->val, max_len);
       
       max_len = max(max_len, ls + rs);
       
       
       return (root->val == expected)? 1 + max(ls, rs) : 0;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        int max_len = 0;
        util(root, root->val, max_len);
        return max_len;
    }
