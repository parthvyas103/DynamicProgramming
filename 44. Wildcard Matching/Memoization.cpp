class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        
        //Base case 1: Both have no characters left then True
        dp[0][0] = true;
        
        //Base Case: 2, Pattern has no chars left
        for(int j=1;j<=m;j++) dp[0][j] = false;
        //Base Case 3: If the input string is exhausted and pattern string has elements left
        for(int i=1;i<=n;i++){
            int flag = true;
            for(int k=1;k<=i;k++){
                if(p[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }
        
        for(int i= 1; i<= n; i++){
            for(int j = 1; j<=m; j++){
                //Case 1: Match or '?'
                if(p[i-1] == s[j-1] || p[i-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                // Case 2: Case with '*', where we either match the * or we start reducing chars due to *
                else if(p[i-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else
                    dp[i][j] = false;
            }
        }
        
        return dp[n][m];
    }
};
