class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        /*
        
        */
        int minSum = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-2; i++){
          int sum = target - nums[i];
          int l = i+1, h = nums.size()-1;
          while(l < h){
            int currSum = nums[l]+nums[h]+nums[i]-target;
            if(currSum==0)return target;
            if(abs(currSum) < abs(minSum))minSum = currSum;
            if(nums[l]+nums[h] > sum)h--;
            else l++;
          }
        }
      return minSum+target;   
    }
    
};