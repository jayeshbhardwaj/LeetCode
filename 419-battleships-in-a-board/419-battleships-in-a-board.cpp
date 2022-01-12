class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        //vector<vector<int>> res(board.size(),vector<int>(board[0].size(),0));
        int cnt=0;
        for(int i=0; i < board.size();i++){
            for(int j=0; j < board[0].size();j++){
                if(board[i][j]=='X'){
                    if((i-1 >= 0
                      && board[i-1][j]=='X')
                       ||
                       (j-1 >= 0
                       && board[i][j-1]=='X')){
                       // res[i][j]=cnt;
                    } else{
                        ++cnt;
                       // res[i][j]=cnt;
                    }
                }
            }
        }
        return cnt;
        
    }
};