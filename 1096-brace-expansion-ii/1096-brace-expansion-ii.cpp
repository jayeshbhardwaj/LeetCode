class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        set<string> res;
        queue<string> q;
        q.push(expression); 
        while(!q.empty()){
          string curr = q.front();
          q.pop();
          if(curr.find('{')==string::npos){
            res.insert(curr);
            continue;
          }
          int left = curr.find('{');
          int id = left;
          while(id < curr.length() && curr[id]!='}'){
            if(curr[id]=='{')left=id;
            id++;
          }
          int right=id;
          string processed = curr.substr(0,left); //prefix string before any left brace {
          vector<string> processing = split(curr.substr(left+1,right-left-1)); // string between first {} 
          string unprocessed = curr.substr(right+1);
          for(auto part : processing){
            //cout<<processed+part+unprocessed<<endl;
            q.push(processed+part+unprocessed);
          }
        }
      return vector<string>(res.begin(),res.end());
    }
  
  vector<string> split(string str){
    //cout<<str<<endl;
    vector<string> res;
    string temp="";
    int i=0;
    while(i < str.length()){
      if(str[i]==','){
        res.push_back(temp);
        temp="";
      } else
        temp=temp+str[i];
      i++;
    }
    res.push_back(temp);
    return res;
  }
};