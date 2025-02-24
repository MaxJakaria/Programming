// Longest Increasing Subsequence(LIS)
#include <bits/stdc++.h>
using namespace std;


class Solution{
	int dp[2510];

public:
	int lis(int i, vector<int> & nums){
		if (dp[i] != -1) return dp[i];

		int ans = 1;
		for (int j = 0; j < i; j++){
			if (nums[j] < nums[i]){
				ans = max(ans, lis(j, nums) + 1);
			}
		}

		return dp[i] = ans;
	}

	int lengthOfLIS(vector<int>& nums){
		memset(dp, -1, sizeof(dp));

		int ans = 1;
		for (int i = 0; i < nums.size(); i++){
			ans = max(ans, lis(i, nums));
		}

		return ans;
	}
};

int main(){
	int n; cin>>n;
	vector<int> nums(n);
	for(int i=0; i<n; i++){
		cin>>nums[i];
	}

	Solution s;
	cout<< s.lengthOfLIS(nums);
}