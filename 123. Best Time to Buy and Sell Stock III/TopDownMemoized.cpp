class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n+1, vector<int>(5, -1));
        //Base case for no transactions
        for(int i = 0; i <= n; i++)
            dp[i][4] = 0;
        //for the last index
        for(int i = 0; i <= 4; i++)
            dp[n][i] = 0;
        
        for(int i = n-1; i >= 0; i--){
            for(int j = 3; j>= 0; j--){
                //Buy
                if(j % 2 ==0)
                    dp[i][j] = max(dp[i+1][j], dp[i+1][j+1] - prices[i]);
                //Sell
                else
                    dp[i][j] = max(dp[i+1][j], dp[i+1][j+1] + prices[i]);
            }
        }
        
        return dp[0][0];
    }
};
