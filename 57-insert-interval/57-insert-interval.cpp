class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int sz=intervals.size();
        int l=0,h=sz-1,ans=-1;
        while(l <= h){
          int m = l + (h-l)/2;
          if(intervals[m][0] >= newInterval[0]){
            h=m-1;
            ans=m;
          } else l=m+1;
        }
        if(ans!=-1)intervals.insert(intervals.begin()+ans,newInterval);
        else intervals.insert(intervals.end(),newInterval);
      
        int start=intervals[0][0],last=intervals[0][1];
        for(int i=1;i <= sz;i++){
          if(intervals[i][0] >  last){
            res.push_back({start,last});
            start = intervals[i][0];
            last  = intervals[i][1];
          } else {
            last = max(last,intervals[i][1]);
          }
        }
          
      res.push_back({start,last});
      return res;
    }
};