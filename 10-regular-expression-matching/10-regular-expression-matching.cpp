class Solution {
public:
    bool isMatch(string s, string p) {
        //recursively
        //s[i]==p[i] || p[i]=="." match
        //p[i]
        //create a tree
        vector<vector<int>> dp(100,vector<int>(31,-1));
            
        function<bool(int,int)> rec = [&](int i, int j){
            //cout<<i<<" "<<j<<endl;
            if(dp[i][j]!=-1)
                return dp[i][j]==1;
            if(j==p.length()) return i==s.length();
            else{
                //if(i >= s.length()) return false;
                bool firstChar = i < s.length() && (s[i] == p[j] || p[j] == '.');
                bool ans=false;
                if(j+1 < p.length() && p[j+1] == '*'){
                    ans = rec(i,j+2)
                        || (firstChar && rec(i+1,j));
                }
                else ans = firstChar && rec(i+1,j+1);
            
                dp[i][j] = ans?1:0;
                return ans;
            }
        };
        return rec(0,0);
    }
};