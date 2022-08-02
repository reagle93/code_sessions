    int util(TreeNode* root, int& max_sum) {
        
        if(root == NULL) {
            return 0;
        }
        
        int ls = max(util(root->left, max_sum), 0);
        int rs = max(util(root->right, max_sum), 0);
        
        max_sum = max(max_sum, ls + rs + root->val);
        
        return max(ls, rs) + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        
        int max_sum = INT_MIN;
        util(root, max_sum);
        
        return max_sum;
    }
