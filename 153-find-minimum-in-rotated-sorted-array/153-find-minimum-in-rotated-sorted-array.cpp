class Solution {
public:
    int findMin(vector<int>& nums) {
     int i = 0; int j = nums.size()-1;
      int ans = nums[0];
      while(i<=j){
        int mid = i + (j-i)/2;
        if(nums[mid] <= nums[nums.size()-1]){
          ans = nums[mid];
          j=mid-1;
        } else i=mid+1;
      }
      return ans;
    }
};