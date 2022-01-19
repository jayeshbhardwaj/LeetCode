class Solution {
public:
    //basic template of recursion + memoization
    bool isMatch(string s, string p) {
        //init memo array
        vector<vector<int>> dp(s.length()+2,vector<int>(p.length()+2,-1));
         //recursive function   
        function<bool(int,int)> rec = [&](int i, int j){
            //cout<<i<<" "<<j<<endl;
           //check base case
            if(j==p.length()) return i==s.length(); //if pattern is exhausted string should be exhausted
            
            //check memo value
            if(dp[i][j]!=-1)return dp[i][j]==1;
            
            //else compute recursively
            bool ans=false;
            if(i > s.length()) return false;
            if(i < s.length() && s[i]==p[j] || p[j]=='?')
                ans = rec(i+1,j+1);
            else if(p[j]=='*'){
                ans = rec(i,j+1) // read 0 char
                      || rec(i+1,j);  //read 1 char
            }
            dp[i][j] = ans?1:0;
            return ans;
        };
        return rec(0,0);
    }
};