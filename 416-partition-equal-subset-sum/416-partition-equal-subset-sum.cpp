class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int s = 0;
        for(auto n : nums)s+=n;
        if(s%2!=0)return false;
        else s=s/2;
        queue<pair<int,int>> q;
        vector<int> visited(s+1,0);
        q.push(make_pair(0,0));
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            //cout<<p.first<<" "<<p.second<<endl;
            visited[p.second]=1;
            if(p.second==s) return true;
            int next=p.first+1;
            //include element
            auto inc = make_pair(p.first+1,p.second+nums[p.first]);
            if( inc.first < nums.size()
              && inc.second <= s 
              && visited[inc.second]==0)
                q.push(inc);
           
            auto exc = make_pair(p.first+1,p.second);
            if(exc.first < nums.size()
              && exc.second <= s)
          //    && visited[exc.second]==0)
                q.push(exc);
            
        }
        
        return false;
    }
};
