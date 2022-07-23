class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {

        vector<vector<int>> ans ;

        vector<vector<bool>> visited( rows, vector<bool>( cols, false ) ) ;

        int top = rStart;
        int left = cStart;
        int right = (cStart + 1 < cols) ?cStart + 1 : cStart ;    
        int down = (rStart + 1 < rows) ? rStart + 1 : rStart;

        ans.push_back({rStart, cStart}) ;
        visited[rStart][cStart] = true ;

        int total = rows*cols;

        while( (int)ans.size() < total ){        

            for( int i = left+1 ; i <= right ; ++i ){

                if(!visited[top][i]){

                    ans.push_back({ top , i }) ;

                    visited[top][i] = true ;
                }
            }

            if(left > 0)
                left--;

            for( int i = top+1 ; i <= down ; ++i ){

                if( !visited[i][right] ){

                    ans.push_back({ i , right }) ;

                    visited[i][right] = true ;
                }
            }

           if( top > 0 ){
                top -= 1 ;
            }       

            for( int i = right-1 ; i >= left ; --i ){

                if( !visited[down][i] ){

                    ans.push_back({ down , i }) ;

                    visited[down][i] = true ;
                }
            }

            if( right + 1 < cols){
                right += 1 ;
            }

            for( int i = down-1 ; i >= top ; --i ){

                if( !visited[i][left] ){

                    ans.push_back({ i, left }) ;

                    visited[i][left] = true ;
                }
            }

            if( down + 1 < rows){
                down += 1;
            }       
        } 
        return ans ;
    }
};
