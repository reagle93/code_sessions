    string findDuplicateSubtreesUtil(TreeNode* root, map<string, int>&mp, TreeNode*&ans, int& max_size) {
        if(root == NULL) {
            return "";
        }
        
        string str = "(";
        str += findDuplicateSubtreesUtil(root->left, mp, ans, max_size);
        str += to_string(root->val);
        str += findDuplicateSubtreesUtil(root->right, mp, ans, max_size);
        str += ")";
        
        if(mp[str] == 1 && str.size() > max_size){
            ans = root;
            max_size = str.size();
        }
        
        mp[str]++;
        return str;
    }
    
    TreeNode* findDuplicateSubtrees(TreeNode* root) {
        map<string, int> mp;
        string str = "";
        TreeNode* ans = NULL;
        int max_size = 0;
        findDuplicateSubtreesUtil(root, mp, ans, max_size);
        return ans;
    }
