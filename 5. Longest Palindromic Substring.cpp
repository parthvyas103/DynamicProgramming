class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        //dp[i][j] represents whether the string from i to j is palindromic or not
        //Putting in values of substring of size 1
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        
        //For lengths of size 2
        int maxLen = 1;
        int start = 0;
        int end = 0;
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]){
                maxLen = 2;
                dp[i][i+1] = 1;
                start = i;
            }
        }
        
        //Size = window size of the string
        //i iterates from the start, j represents the end
        // 
        for(int size = 3; size <= n; size++){
            for(int i = 0; i < n - size+1; i++){
                int j = i + size - 1;
                if(dp[i+1][j-1] == 1 && s[i] == s[j]){
                    dp[i][j] = 1;
                    if(size > maxLen){
                        maxLen = size;
                        start = i;
                    }
                }
            }
        }
        
        return s.substr(start, maxLen);
    }   
};
