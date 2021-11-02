class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
      int res = 1;
      int n = arr.size();
      vector<int> index(n);
      for(int i=0 ;i < n;i++)index[i]=i;
      auto cmp_odd = [&arr](const int x, const int y){
        return arr[x] < arr[y] || (arr[x] == arr[y] && x < y) ;
      };
      auto cmp_even = [&arr](const int x, const int y){
        return arr[x] > arr[y] || (arr[x] == arr[y] && x < y) ;
      };
      
      auto next_higher = [](vector<int>& index) -> vector<int> {
        int n = index.size();
        stack<int> s;
        vector<int> next_higher(n);
        int i = 0;
        for(int i = 0; i < n; i++){
          while(!s.empty() && index[i] > s.top()){
            next_higher[s.top()] = index[i];
            s.pop();
          }
          s.push(index[i]);
        }
        while(!s.empty()){
          next_higher[s.top()] = -1;
          s.pop();
        }
        return next_higher;
      };
      
      sort(index.begin(),index.end(),cmp_odd);
      vector<int> odd_next = next_higher(index);
      sort(index.begin(),index.end(),cmp_even);
      vector<int> even_next = next_higher(index);
      
      vector<bool> odd(n);
      vector<bool> even(n);
      odd[n-1]=true;
      even[n-1]=true;
      
      for(int i = n-2; i>=0 ; i--){
        //using bounds in map
        //auto hi = num.lower_bound(arr[i]), lo = num.upper_bound(arr[i]); 
        //if(hi!=num.end())odd[i]=even[hi->second];
        //if(lo!=num.begin())even[i]=odd[(--lo)->second];
        auto hi = odd_next[i], lo = even_next[i];
        if(hi!=-1)odd[i]=even[hi];
        if(lo!=-1)even[i]=odd[lo];
        if(odd[i])res++;  
      } 
      return res;
    }
   
  
};