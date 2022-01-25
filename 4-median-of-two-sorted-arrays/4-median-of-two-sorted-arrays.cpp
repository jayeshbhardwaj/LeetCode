class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
      int i=0,j=0;
      priority_queue<int,vector<int>,greater<int>> min_h;
      priority_queue<int,vector<int>,less<int>> max_h;
      
      auto resize = [&](){
        if(min_h.size() > max_h.size()){
          int num = min_h.top();
          min_h.pop();
          max_h.push(num);
        } else{
          int num = max_h.top();
          max_h.pop();
          min_h.push(num);
        }
        
      };
      
      while(i < nums1.size() || j < nums2.size()){
        int numToAdd = -1;
        if(j == nums2.size() || (i < nums1.size() && nums1[i] <= nums2[j])){
          numToAdd=nums1[i];
          i++;
        } else if(i == nums1.size() || (j < nums2.size() && nums2[j] <= nums1[i])){
          numToAdd=nums2[j];
          j++;
        }
        int s1=max_h.size();
        int s2=min_h.size();
        if(s1==0)max_h.push(numToAdd);
        else if(s2==0)min_h.push(numToAdd);
        else{
          if(numToAdd <= max_h.top())max_h.push(numToAdd);  
          else min_h.push(numToAdd);
        }
        int diff = min_h.size()-max_h.size();
        if(abs(diff) > 1){
          resize();
        } 
      }
      
      bool isEven = (nums1.size() + nums2.size())%2==0;
      
      if(isEven)return (min_h.top()+max_h.top())/2.0;
      else{
        if(max_h.size() > min_h.size()) return max_h.top()*1.0;
        else return min_h.top()*1.0;
      }
      
    }
   
};