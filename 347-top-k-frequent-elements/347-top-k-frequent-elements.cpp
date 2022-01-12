class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int> count;
        int maxCount=0;
        for(int i=0; i < nums.size();i++){
            count[nums[i]]+=1;
            if(count[nums[i]] > maxCount)
                maxCount = count[nums[i]];
        }
        // buckets 1 to maxCount
        vector<vector<int>> buckets(maxCount+1,vector<int>());
        
        for(auto it : count){
            buckets[it.second].push_back(it.first);
        }
        
        vector<int> res;
        int i=0,cnt=0;
        while(i < nums.size() && cnt < k){
            for(auto elems : buckets[maxCount-i]){
                res.push_back(elems);
                cnt++;
            }    
            i++;
        }
        
        return vector<int>(res.begin(),res.begin()+k);
        
        
        
        
    }
};

/*
k most frequent
map<count, set of integers>
1-> 

3 -> 1
2 -> 2
1 -> 3
*/