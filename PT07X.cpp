#include <bits/stdc++.h>
using namespace std;
#define MX 100005
vector <int> g[MX];
int dp[MX][2];
int dfs (int u, int par, bool t) {
    int &ret = dp[u][t];
    if (ret != -1) return ret;
    int mn;
    ret = 0;
    int sz = g[u].size();
    for (int i = 0; i < sz; i++) {
        int v = g[u][i];
        if (v == par) continue;
        mn = 1 + dfs (v, u, 1);
        if (t == 1 || par == -1) mn = min (mn, dfs(v, u, 0));
        ret += mn;
    }
    return ret;
}
int main()
{
    
    int n, u, v, x;
    scanf (" %d", &n);
    memset (dp, -1, sizeof (dp));
    for (int i = 0; i < n-1; i++) {
        scanf (" %d %d", &u, &v);
        g[u].push_back (v);
        g[v].push_back (u);
    }
    g[0].push_back (1);
    //ans = min (dfs(1, -1, 0), 1+dfs(1, -1, 1)); printf ("%d\n", ans);
    printf ("%d\n", dfs (0, -1, 0) );
    return 0;
}
