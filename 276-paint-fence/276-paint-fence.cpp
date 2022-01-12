class Solution {
public:
    int numWays(int n, int k) {
      int dp[51]={0};
      dp[2]=k*k;
      dp[1]=k;
     function<int(int)> recur = [&](int i){
      if(dp[i] > 0) return dp[i]; 
      dp[i] = recur(i-1)*(k-1) + recur(i-2)*(k-1);
      return dp[i];
     };
      return recur(n);
    }
};