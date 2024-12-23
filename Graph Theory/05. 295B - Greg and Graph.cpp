#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 501;

vector<int> del_order;
vector<vector<ll>> dist;

void solve(int &n){
    reverse(del_order.begin(), del_order.end());
    
    vector<ll> ans;
    for(int k=0; k<n; k++){
        ll k_v = del_order[k];

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                ll new_dist = dist[i][k_v] + dist[k_v][j];
                dist[i][j] = min(dist[i][j], new_dist);
            }
        }

        ll sum = 0;
        for(int i=0; i<=k; i++){
            for(int j=0; j<=k; j++){
                sum += dist[del_order[i]][del_order[j]];
            }
        }
        ans.push_back(sum);
    }

    reverse(ans.begin(), ans.end());
    for(int i=0; i<n; i++)
        (i == n-1)? cout<< ans[i]: cout<< ans[i]<< ' ';
}


int main(){
    int n; cin >> n;

    dist = vector<vector<ll>>(n + 1, vector<ll>(n + 1));
    del_order = vector<int>(n);

    for(int i=1;i<=n;i++)
        for(int j=1; j<=n; j++)
            cin>>dist[i][j];
    
    for(int i=0; i<n; i++)
        cin>>del_order[i];

    solve(n);
    
    return 0;
}
