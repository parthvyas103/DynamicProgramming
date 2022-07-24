class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int curr = 0;
        
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i-1]){
                curr = prices[i] - prices[i-1];
                res = res + curr;
            }    
        }
        
        return res;
    }
};
