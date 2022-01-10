class Solution {
public:
    int maxArea(vector<int>& height) {
      int l = 0, h=height.size()-1;
      int res = 0;
      while(l < h){
        if((h-l)*min(height[h],height[l]) > res)
          res = (h-l)*min(height[h],height[l]);
        if(height[l] < height[h]){
          int s = l+1;
          while(s < h && height[s] <= height[l])s++;
          l=s;
        } else {
          int s = h-1;
          while(s > l && height[s] <= height[h])s--;
          h=s;
        }  
      }
      return res;
    }
};