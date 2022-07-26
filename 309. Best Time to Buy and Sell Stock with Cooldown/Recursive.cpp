class Solution {
public:
    int solve(vector<int> &prices, int i, bool cooldown, bool buy){
        if(i == prices.size()) return 0;
        if(cooldown){
            return solve(prices, i+1, !cooldown, buy);
        }
        
        //buy
        if(buy){
            return max(solve(prices, i+1, cooldown, buy), -prices[i] + solve(prices, i+1, cooldown, 0));
        }
        //sell
        else{
            int sell = prices[i] + solve(prices, i+1, !cooldown, 1);
            int dont = solve(prices, i+1, cooldown, 0);
            return max(sell, dont);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        return solve(prices, 0, 0, 1);
    }
};
