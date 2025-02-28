#include <bits/stdc++.h>
using namespace std;

long long knapSack(int W, vector<int> &weight, vector<int> &value){
    vector<long long> dp(W+2,0);
    for(int i=1; i<=weight.size(); i++){
        for(int w = W; w>=0; w--){
            if(weight[i] <= w){
                dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
            }
        }
    }

    return dp[W];
}

int main() {
    int N, W; cin>> N>> W;
    vector<int> weight(N+1), value(N+1);
    for(int i=1; i<=N; i++){
        cin>> weight[i]>> value[i];
    }

    cout<< knapSack(W, weight, value)<< '\n';
    return 0;
}
