class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      int n = matrix.size();
       auto comp = [&](pair<int,int> a, pair<int,int> b){
         return matrix[a.first][a.second] > matrix[b.first][b.second];  
       }; 
      priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
      pq.push(make_pair(0,0));
      //pq.push(make_pair(0,1));
      int cnt=0;
      while(!pq.empty()){
          auto p = pq.top();
          pq.pop();
          cnt++;
          if(cnt==k)return matrix[p.first][p.second];
          if(p.second < n-1)
              pq.push(make_pair(p.first,p.second+1));
          if(p.second==0 && p.first < n-1)
              pq.push(make_pair(p.first+1,p.second));
      }
        return -1;
  }
};