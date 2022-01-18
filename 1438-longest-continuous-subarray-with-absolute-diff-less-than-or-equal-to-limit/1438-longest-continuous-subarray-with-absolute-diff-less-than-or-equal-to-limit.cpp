class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
     
        int res=1;
        int s=0;
        map<int,int> last;
        last[nums[0]]=0;
        for(int j=1; j < nums.size();j++){
            bool found=true;
            int newStart=-1;
            for(auto ent : last){
               if(abs(nums[j]-ent.first) > limit){
                   found=false;
                   newStart=max(newStart,ent.second);
                   //break;
               }             
            }
            if(!found){
                res=max(res,j-s);
                //cout<<res<<" "<<j<<endl;
                while(s < newStart+1){
                    if(last[nums[s]]==s)last.erase(nums[s]);
                    s++;
                }
            }
            last[nums[j]]=j;
            
        }
        int l=nums.size();
        res=max(res,l-s);
        return res;
    }
};