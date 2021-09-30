class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        auto shift = [](int x){
            return 1 << (10-x+1);
        };
        map<int,unsigned int> resv;
        for(int i = 0; i < reservedSeats.size();i++){
            unsigned int prev = resv.find(reservedSeats[i][0])==resv.end()?0:resv[reservedSeats[i][0]];
            resv[reservedSeats[i][0]] =  (prev | shift(reservedSeats[i][1]));
        }
        int res = 0;
        for (std::map<int,unsigned int>::iterator it=resv.begin(); it!=resv.end(); ++it){
            int val = ~(it->second);
            bool flag = false;
            int f = shift(2)|shift(3)|shift(4)|shift(5);
            if((val & f) == f){
                flag = true;
                res = res + 1;
            }
             f = shift(6)|shift(7)|shift(8)|shift(9);
            if((val&f)==f){
                flag = true;
                res = res + 1;
            }
               f = shift(6)|shift(7)|shift(4)|shift(5);
            if((val&f) == f && flag == false){
                res = res + 1;
            }
        
        }
        cout<<res<<endl;
        return res + (n-resv.size())*2;
    }
};