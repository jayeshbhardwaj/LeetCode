class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> prod(nums.size());
        vector<int> prod2(nums.size());

        prod[0] = prod2[0] = nums[0];
        
        int maxProd = prod[0];
        for(int i = 1; i < nums.size();i++){
          prod2[i] = min(nums[i],min(nums[i]*prod[i-1],nums[i]*prod2[i-1]));
          prod[i] = max(nums[i],max(nums[i]*prod2[i-1],nums[i]*prod[i-1]));
          maxProd = max(maxProd,prod[i]);
        }
        return maxProd;
    }
};