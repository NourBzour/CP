#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()

int const N = 200001;
int n, out[N]; 
vector<int>g[N], node[N];
bool vs[N];

void go(int u, int pa){
     vs[u] = true;
     for(auto i: g[u]){
        if(!vs[i]){go(i, u); out[u] += out[i]+1;}
        else {
           out[u] += out[i]+1;   
        }
     }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("read.txt","r",stdin);
    #endif
    scanf("%d", &n);
    for(int i = 0, u, v; i<n-1; ++i){
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
    }
    int mx = 0;
    for(int i = 1; i<=n; ++i){
       if(!vs[i])go(i, i);
       mx = max(mx, out[i]);
       node[out[i]].push_back(i);
    }
    int root = node[mx].back();
    memset(vs, 0, sizeof vs);
} 