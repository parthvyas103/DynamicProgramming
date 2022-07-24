//SHOULD WORK BUT DID NOT

class Solution {
public:
    bool solve(vector<vector<int>> &dp, int i, int j, string &p, string &s){
        // All Stars exhausted
        if(i < 0 && j < 0) return true;
        // Pattern Exhauted but string still left
        if(i < 0 && j >= 0) return false;
        // Pattern left but string gone
        if(i >= 0 && j < 0){
            for(int k = 0; k <= i; k++){
                if(p[k] != '*') return false;
            }
            return false;
        }
        if(dp[i][j] != -1) return dp[i][j];
        //? and matching case
        if(p[i] == s[j] || p[i] == '?')
            return dp[i][j] = solve(dp, i-1, j-1, p, s);
        //Case 1: Ignore the * and move on
        //Case 2: Start removing the characters and assume the * operation
        else{
            if(p[i] == '*')
                return dp[i][j] =  solve(dp, i-1, j, p, s) || solve(dp, i, j-1, p, s);
            else return dp[i][j]= false;
        }
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(dp, m-1, n-1, p, s);
    }
};
