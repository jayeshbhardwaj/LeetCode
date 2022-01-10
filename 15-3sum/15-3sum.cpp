class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> res;  
      if(nums.size() < 3) return res;
      
      /*
      A[I]+A[J]+A[k] = 0
      Brute force:
      For every pair in nums, do binary search for its negation in nums
      how to avoid duplicates? set bounds for binary search
      */
      sort(nums.begin(),nums.end());
      for(int i=0;i < nums.size()-2;i++){
        if(i==0 || nums[i]!=nums[i-1]){
           int sum=0-nums[i],l=i+1,h=nums.size()-1;
            while(l < h){
             if(nums[l]+nums[h] == sum){
               vector<int> v(3);
               v[0]=nums[l];v[1]=nums[h];v[2]=nums[i];
               res.push_back(v);
               l++;h--;
               while(l < h && nums[l]==nums[l-1])l++;
               while(l < h && nums[h]==nums[h+1])h--;
             }
              else if(nums[l]+nums[h] > sum){
                h--;
                while(l < h && nums[h]==nums[h+1])h--;
              } 
              else{
                l++;
                while(l < h && nums[l]==nums[l-1])l++;
              }
            }
        }
      }
      return res;
    }
    
};