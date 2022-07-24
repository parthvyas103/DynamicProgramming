class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=  0;
        int m = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            m = min(m, prices[i]);
            res = max(res, prices[i] - m);a
        }
        return res;
    }
};
