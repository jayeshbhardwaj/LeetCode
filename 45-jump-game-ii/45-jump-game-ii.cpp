class Solution {
public:
    int jump(vector<int>& nums) {
      if(nums.size()==1)return 0;
   
      vector<int> steps(nums.size(),0);
      int currEnd=0;
      int maxEnd=0;
      int count=0;
      for(int i = 0; i < nums.size();i++){
       maxEnd=max(maxEnd,nums[i]+i);
       steps[i]=count;
       if(i == currEnd){
         count++;
         currEnd = maxEnd;
       }
      }
      return steps[nums.size()-1];
    }
};