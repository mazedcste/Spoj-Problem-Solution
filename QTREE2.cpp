#include <bits/stdc++.h>
using namespace std;
//LCA using sparse table
//Complexity: O(NlgN,lgN)
#define mx 10002
#define pb push_back
int L[mx]; //label
int dis[mx]; //distance from root
int ST[mx][33]; //Sparse Table
int P[mx]; //Parent
vector<int>g[mx];
vector<int>cost[mx];
void dfs (int u, int par, int dist, int label) {
    L[u] = label;
    dis[u] = dist;
    P[u] = par;
    int sz = g[u].size();
    for (int i = 0; i < sz; i++) {
        int v = g[u][i], w = cost[u][i];
        dfs (v, u, dist+w, label+1);
    }
}
void lca_init (int n) {
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 33; j++) ST[i][j] = -1;

    for (int j = 0; j <= n; j++) ST[j][0] = P[j]; //2^0 th parent

    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 0; i <= n; i++)
            if (ST[i][j-1] != -1) ST[i][j] = ST[ ST[i][j-1] ][j-1];

}
int find_lca (int u, int v) {
    if (L[u] < L[v]) swap (u, v);
    for (int i = 30; i >= 0; i--)
        if (L[u] - (1 << i) >= L[v]) u = ST[u][i];

    if (u == v) return u;
    //cout << u << " " << v << endl;
    for (int i = 30; i >= 0; i--) {
        if (ST[u][i] != -1 && ST[u][i] != ST[v][i]) {
            u = ST[u][i]; v = ST[v][i];
        }
    }
    return P[u];
}

int main()
{
    int n, e, u, v, q, tc, w, k;
    string s;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d", &n);
        for (int i = 0; i < n-1; i++) {
            scanf (" %d %d %d", &u, &v, &w);
            g[u].pb (v);
            cost[u].pb (w);
        }
        g[0].pb(1);
        cost[0].pb(0);
        memset (P, -1, sizeof (P));
        dfs (1, 0, 0, 0);
        lca_init(n);
        while (cin >> s) {
            if (s == "DONE") break;
            if (s == "DIST") {
                scanf (" %d %d", &u, &v);
                int lc = find_lca(u, v);
                printf ("%d\n", dis[u]-dis[lc] + dis[v]-dis[lc]);
            }
            else if (s == "KTH") {
                scanf ("%d %d %d", &u, &v, &k);
                int lc = find_lca (u, v);
                if (L[u]-L[lc] >= k-1) {
                    int p = L[u] - k+1;
                    for (int i = 30; i >= 0; i--)
                        if (L[u] - (1 << i) >= p) u = ST[u][i];
                    printf ("%d\n", u);
                }
                else {
                    int p = L[lc] + k-1-(L[u]-L[lc]);
                    for (int i = 30; i >= 0; i--) {
                        if (L[v] - (1 << i) >= p) v = ST[v][i];
                    }
                    printf ("%d\n", v);
                }
            }
        }
        vector<int>tt[mx], ttt[mx];
        swap (tt, g); swap (ttt, cost);

    }
    return 0;
}

