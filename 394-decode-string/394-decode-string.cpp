class Solution {
public:
    string decodeString(string s) {
        stack<string> strs;
        stack<int> counts;
        string result="";
        strs.push("");
        counts.push(0);
        int cnt=0;
        for(int i=0; i < s.length();i++){
           if(s[i] >= 'a' && s[i] <= 'z'){
               string ntop = strs.top() + s[i];
               strs.pop();strs.push(ntop);
           } else if(s[i] >= '0' && s[i] <= '9'){
               //build count
               cnt=cnt*10 + s[i]-'0';
           } else if(s[i]=='['){
               counts.push(cnt);
               cnt=0;
               strs.push("");
           } else {
               string curr = strs.top();
               int cnt = counts.top();
               strs.pop();
               counts.pop();
               string res="";
               for(int j=0; j < cnt;j++){
                   res=res+curr;
               }
               string tops = strs.empty()?"":strs.top();
               if(!strs.empty())strs.pop();
               strs.push(tops+res);
           }
        }
        
        return strs.top();
    }
};

/*
2[3[a2[c]de]a]
0,1,2,3,4,5,6 ->]
a,c,c,d,e

*/