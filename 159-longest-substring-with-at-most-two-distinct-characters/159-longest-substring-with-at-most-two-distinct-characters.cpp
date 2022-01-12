class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int i=0,j=0,maxLen=0,count=0;
        vector<int> freq(128,0);
        while(j < s.size()){
          freq[s[j]]++;
          if(freq[s[j]]==1)count++;
          if(count > 2){
            if(j-i > maxLen)maxLen=j-i;
            while(i < s.size() && count > 2){
             freq[s[i]]--;
             if(freq[s[i]]==0)count--;
              i++;
            }
          } 
          j++;
        }
      return max(maxLen,j-i);
    }
};