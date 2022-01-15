class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //priority queue of num outgoing edges
        //build adj list string to set of strings
        map<string,priority_queue<string,vector<string>, greater<string>>> graph;
        for(auto ticket : tickets){
            graph[ticket[0]].push(ticket[1]);
        }
        
        vector<string> res;
        function<void(string)> dfs = [&](string curr){
            //cout<<curr<<endl;
            auto q = graph[curr];
            while(!graph[curr].empty()){
                auto next = graph[curr].top();
                graph[curr].pop();
                dfs(next);
                
            }
            res.push_back(curr);
        };
        
        
        dfs("JFK");
        reverse(res.begin(),res.end());
        return res;
    }
};