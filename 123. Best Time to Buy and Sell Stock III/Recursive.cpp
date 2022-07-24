class Solution {
public:
    
    //At Most Two transactions
    //You must sell before buying
    
    //f(i) -> max value of two transactions 
    
    int solve(vector<int> &prices, int i, int cnt, int buyprice){
        if(cnt == 0) return 0;
        if(i > prices.size() -1 ) return 0;
        //Sell Logic
        if(buyprice != INT_MAX){
            int skip = solve(prices, i+1, cnt, buyprice);
            int sell = prices[i] - buyprice + solve(prices, i+1, cnt-1, INT_MAX);
            return max(skip, sell);
        }
        else{
            int buy = solve(prices, i+1, cnt, prices[i]);
            int dont = solve(prices, i+1, cnt, buyprice);
            return max(buy, dont);
        }
    }
    int maxProfit(vector<int>& prices) {
        int res = solve(prices, 0, 2, INT_MAX);
        return res;
    }
};
