class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      int l=0,r=nums.size()-1;
      while(l<=r){
        int m = l + (r-l)/2;
        if((m==0 || nums[m] > nums[m-1]) &&
           (m == nums.size()-1 || nums[m] > nums[m+1])){
          return m;
        } 
        // if its increasing then peak is definitely in this half
        else if(nums[m] < nums[m+1]) l=m+1;
        else r = m-1;      
      }
      return -1;
    }
};