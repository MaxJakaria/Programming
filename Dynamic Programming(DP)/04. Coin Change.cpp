class Solution {
	long long dp[10010];
public:
	int fun(vector<int> &coins, int amount){
		if(dp[amount] != -1) return dp[amount];
		if(amount == 0) return 0;
		int ans = INT_MAX;
		
		for(auto &coin: coins){
			if(amount - coin >= 0)
				ans = min(ans+0ll, fun(coins, amount-coin)+1ll);
		}

		return dp[amount] = ans;
	}
    int coinChange(vector<int>& coins, int amount) {
    	memset(dp, -1, sizeof(dp));
    	long long ans = fun(coins, amount);
        return (ans == INT_MAX)? -1: ans;
    }
};