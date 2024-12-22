#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
vector<int> graph[N];
vector<int> vis(N, 0);

int dfs(int vertex){
    vis[vertex]++;
    if(vis[vertex] == 2) return vertex; 

    for (int child : graph[vertex]){  
        if (vis[child] < 2){
            return dfs(child);
        }
    }
}

int main(){
    int n; cin >> n;
    
    for(int i = 1; i <= n; i++){
        int v; cin >> v;
        graph[i].push_back(v);
    }

    for(int i = 1; i <= n; i++){
        fill(vis.begin(), vis.end(), 0);

        if(i==n){
            cout<< dfs(i);
            break;
        }
        cout << dfs(i) << ' ';
    }
    return 0;
}
