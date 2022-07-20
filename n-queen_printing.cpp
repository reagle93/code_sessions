class Solution {
public:
    
    
    bool canPlace(vector<int>&set, int col, int i){

        for (int j = 0;j <= col - 1;j++){
            if (set[j] == i ||
                (abs(set[j] - i) == abs(j - col))) //same row or diagnonal
            return false;
        }
        return true;
    }


    void nQueens(vector<vector<int> >& res, vector<int>& set, int col, int n){
        
        if (col == n) {
            res.push_back(set);
            return ;
        }

        for (int i = 0;i < n;i++){
            
            if (canPlace(set, col, i)){
                
                set[col] = i;
                nQueens(res, set, col + 1, n);
                set[col] = 0;
            }
        }
    }

    
    
    vector<vector<string>> solveNQueens(int n) {
        
        
        vector<vector<int>> res;

        vector<int> set(n, 0);

        nQueens(res, set, 0, n);
                
        vector<vector<string>> ans;
        
        
        for(int i =0;i<res.size();i++) {
            
            string temp = "";
            for(int j =0;j<n;j++)
                temp += ".";
            
            vector<string> board(n, temp);
            
            for(int j=0;j<n;j++)
                board[j][res[i][j]] = 'Q';
            
            ans.push_back(board);
        }
              
        return ans;
    }
};








