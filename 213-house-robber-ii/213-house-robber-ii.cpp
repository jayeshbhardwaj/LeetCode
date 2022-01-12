class Solution {
public:
    int rob(vector<int>& nums) {
      int sz = nums.size();
      if(sz==1)return nums[0];
      if(sz==2)return max(nums[0],nums[1]);
      return max(robHouse(nums,0,sz-2),robHouse(nums,1,sz-1));
      
    }
    int robHouse(vector<int> a, int s, int e){
      vector<int> dp(e-s+1,0);
      dp[0]=a[s];
      dp[1]=max(a[s],a[s+1]);
      for(int i=s+2; i <=e; i++){
        dp[i-s]=max(dp[i-s-1],dp[i-s-2]+a[i]);
      }
      return dp[e-s];
    }
};