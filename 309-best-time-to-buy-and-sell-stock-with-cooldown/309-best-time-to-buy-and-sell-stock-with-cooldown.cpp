class Solution {
public:
    int maxProfit(vector<int>& prices) {
      if(prices.size() < 2)return 0;
      int buy=-prices[0];
      int sell=0;
      int hold=0;
      int res=0;
      for(int i=1; i < prices.size();i++){
        //states[1] = -prices[i];
       int prevSell = sell; 
       sell = buy+prices[i]; //sell can only happen from 
       buy = max(buy,hold-prices[i]); //buy: either stay at prev buy or buy current price
       hold = max(hold,prevSell); //cooldown: can only come from sell
      }
      return max(hold,sell);    
    }
};