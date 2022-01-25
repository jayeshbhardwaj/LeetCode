class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int sz = s.length();
        if(k > sz) return 0;
        int i=0,j=0;
        vector<int> loc(26,-1);
        int res=0;
        while(j < sz){
          if(loc[s[j]-'a'] >= i){
            i=loc[s[j]-'a']+1;
          }
           
          loc[s[j]-'a'] = j;
          j++;
          
          if(j-i-k >= 0){
              res=res + 1;
           }
         
       }
      return res;
    }
};