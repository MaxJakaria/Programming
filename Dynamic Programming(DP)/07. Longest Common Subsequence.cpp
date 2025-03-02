class Solution {
    int dp[1010][1010];

public:
    int lcs(int i,int j,string &text1, string &text2){
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = max(lcs(i-1, j, text1, text2), lcs(i, j-1, text1, text2));
        ans = max(ans, lcs(i-1, j-1, text1, text2) + (text1[i-1] == text2[j-1]));
        return dp[i][j] = ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        
        int n = text1.size();
        int m = text2.size();
        return lcs(n, m, text1, text2);
    }
};
