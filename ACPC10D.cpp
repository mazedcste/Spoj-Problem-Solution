#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL a[100001][3];
LL dp[300005];
int n;
LL func (int u) {
    if (dp[u] != -1) return dp[u];

    if (u/3 == n-1) {
        if (u %3 == 0) return dp[u] = a[u/3][u%3] + func (u+1);
        else if (u %3 == 1) return dp[u] = a[u/3][u%3];
        else if (u %3 == 2) return dp[u] = 1e16;
    }
    LL r;
    if (u %3 == 0) {
        r = a[u/3][u%3]+func (u+1);
        r = min (r, a[u/3][u%3]+func (u+3));
        r = min (r, a[u/3][u%3]+func (u+4));
    }
    else if (u %3 == 1) {
        r = a[u/3][u%3]+func (u+1);
        r = min (r, a[u/3][u%3]+func (u+2));
        r = min (r, a[u/3][u%3]+func (u+3));
        r = min (r, a[u/3][u%3]+func (u+4));
    }
    else if (u %3 == 2) {
        r = a[u/3][u%3]+func (u+2);
        r = min (r, a[u/3][u%3]+func (u+3));
    }
    return dp[u] = r;
}
int main ()
{
    int cs = 1;
    while (scanf (" %d", &n) == 1) {
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf (" %lld %lld %lld", &a[i][0], &a[i][1], &a[i][2]);
        }
        memset (dp, -1, sizeof (dp));
        printf ("%d. %lld\n", cs++, func (1));
    }

    return 0;
}
