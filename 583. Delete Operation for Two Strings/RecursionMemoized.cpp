class Solution {
public:
    int solve(string word1, string word2, int i, int j, vector<vector<int>> &dp){
        //If both the string reach the end the nothing to release
        
        if(i == word1.size() && j == word2.size()) return 0;
        
        //If we reach end of word1
        if(i == word1.size()) return word2.size() - j;
        
        //If we reach end of word2
        if(j == word2.size()) return word1.size() - i;
        
        if(dp[i][j] != 1000) return dp[i][j];
        
        //In case of same character
        if(word1[i] == word2[j]) return solve(word1, word2, i+1, j+1, dp);
        
        //Choice of both
        int o1 = solve(word1, word2, i+1, j, dp);
        int o2 = solve(word1, word2, i, j+1, dp);
        
        return  1 + min(o1, o2);
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), 1000));
        return solve(word1, word2, 0, 0, dp);
    }
};
