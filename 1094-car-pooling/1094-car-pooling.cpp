class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       map<int,int> hash;
       for(int i = 0;i < trips.size();i++){
         hash[trips[i][1]]+=trips[i][0];
         hash[trips[i][2]]-=trips[i][0];
       }
      int curr=0;
       for(auto &iter : hash){
         curr = curr + iter.second;
         if(curr > capacity) return false;
       }
      return true;
    }
};