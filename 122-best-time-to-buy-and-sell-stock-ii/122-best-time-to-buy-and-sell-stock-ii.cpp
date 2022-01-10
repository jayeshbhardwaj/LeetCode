class Solution {
public:
    int maxProfit(vector<int>& prices) {
      deque<int> q;
      int res=0;
      for(int i=0; i < prices.size();i++){
        int p = 0;
        if(!q.empty() && prices[q.back()] > prices[i]){
          p =  prices[q.back()]-prices[q.front()];
          q.clear();
        }
        //cout<<p<<endl;
        q.push_back(i);
        res=res+p;
      }
      if(!q.empty())res += prices[q.back()]-prices[q.front()];
      return res;
      
    }
};