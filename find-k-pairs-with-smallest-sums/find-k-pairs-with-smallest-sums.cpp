class Solution {
int speedup = [] { ios::sync_with_stdio(0); cin.tie(0); return 0; }();
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      
      vector<vector<int>> vec ;
      //true -> swap, false -> noswap
      // if x > y i.e if heap top element is greater than curr elem then swap
      auto compare = [&](pair<int,int> x,pair<int,int> y){
            return (nums1[x.first]+nums2[x.second]) > (nums1[y.first]+nums2[y.second]);
        };
        
      priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(compare)>pq(compare);
      k = k > nums1.size()*nums2.size()?nums1.size()*nums2.size():k;
     
      pq.push(make_pair(0,0));
        
      while(pq.size() > 0 && vec.size() < k){
        auto [n1,n2] = pq.top();
        vec.push_back({nums1[n1],nums2[n2]});
        pq.pop();
        
        if(n2+1 < nums2.size()){
          pq.push(make_pair(n1,n2+1));
        }
        if(n2==0 && n1+1 < nums1.size()){
          pq.push(make_pair(n1+1,n2));
        }
      }
        return vec;
    }
 
};