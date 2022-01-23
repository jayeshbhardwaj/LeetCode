class Solution {
public:
    int countElements(vector<int>& nums) {
        map<int,int> hash;
        for(auto n : nums)hash[n]+=1;
        auto start = hash.begin();
        ++start;
        auto end = hash.end();
        --end;
       int res=0;
       for(auto it = start;it!=end;++it){
         res+=it->second;
       }
      return res;
    }
};