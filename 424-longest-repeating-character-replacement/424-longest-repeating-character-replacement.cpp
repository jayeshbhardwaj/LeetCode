class Solution {
public:
    int characterReplacement(string s, int k) {
     int freq[26] = {0};
        int i=0, maxFreq=0;
        int res=0;
     for(int j=0; j < s.length();j++){
         freq[s[j]-'A']+=1;
         maxFreq = max(maxFreq,freq[s[j]-'A']);
         // shrink window
         if((j-i+1) - maxFreq > k){
             while((j-i+1) - freq[s[i]-'A'] > k){
                 freq[s[i]-'A']-=1;
                 i++;
             }
         }
         res=max(res,j-i+1);
         //end of window extending
     }
        
        return res;
        
    }
};