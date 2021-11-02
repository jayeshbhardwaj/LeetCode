class Solution {
    
public:
    int oddEvenJumps(vector<int>& arr) {
      int res = 1;
      int n = arr.size();
      map<int,int> num;
      vector<int> odd(n);
      vector<int> even(n);
      odd[n-1]=even[n-1]=1;
      num.insert(make_pair(arr[n-1],n-1));
      for(int i = n-2; i>=0 ; i--){
        auto hi = num.lower_bound(arr[i]), lo = num.upper_bound(arr[i]); 
        if(hi!=num.end())odd[i]=even[hi->second];
        if(lo!=num.begin())even[i]=odd[(--lo)->second];
        if(odd[i])res++;  
        num[arr[i]]=i;
      } 
      return res;
    }
   
};