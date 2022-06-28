vector<int> isPoss(int arr[], int n, int sum){
        bool dp[n+1][sum+1];
        
        for(int i = 0; i <= sum; i++)
            dp[0][i] = false;
        
        for(int i = 0; i <= n; i++)
            dp[i][0] = true;
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                if(arr[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
        
        
        vector<int> res;
        
        for(int i = 0; i < sum+1; i++)
            if(dp[n][i])
                res.push_back(i);
        return res;
    }
    
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    
	    for(int i = 0; i < n; i++)
	        sum += arr[i];
	        
	    vector<int> ops = isPoss(arr, n, sum);
	    
	    int res = INT_MAX;
	    
	    for(auto x: ops){
	        res = min(res, abs(2*x - sum));    
	    }
	    
	    return res;
	} 
