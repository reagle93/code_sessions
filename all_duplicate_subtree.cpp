    string findDuplicateSubtreesUtil(TreeNode* root, map<string, int>&mp, vector<TreeNode*>&ans) {
        if(root == NULL) {
            return "";
        }
        
        string str = "(";
        str += findDuplicateSubtreesUtil(root->left, mp, ans);
        str += to_string(root->val);
        str += findDuplicateSubtreesUtil(root->right, mp, ans);
        str += ")";
        
        if(mp[str] == 1){
            ans.push_back(root);
        }
        
        mp[str]++;
        return str;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string, int> mp;
        vector<TreeNode*> ans;
        string str = "";
        findDuplicateSubtreesUtil(root, mp, ans);
        return ans;
    }
