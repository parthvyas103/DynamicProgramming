class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
    
        for(int i = n-1; i >= 0; i--){
            for(int j = 2*k-1; j >= 0; j--){
                if(j % 2 == 0)
                    dp[i][j] = max(dp[i+1][j], -prices[i] + dp[i+1][j+1]);
                else
                    dp[i][j] = max(dp[i+1][j], prices[i] + dp[i+1][j+1]);
            }
        }
        
        return dp[0][0];
    }
};
