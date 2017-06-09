#include <bits/stdc++.h>
using namespace std;
int slen, tlen, k;
int dp[1001][1001];
char s[1001], t[1001];
int main ()
{
    //freopen ("in.txt", "r", stdin);
    while (scanf (" %d", &k) == 1) {
        if (k == 0) break;
        memset (dp, 0, sizeof (dp));
        scanf (" %s %s", s+1, t+1);
        slen = strlen (s+1);
        tlen = strlen (t+1);
        for (int i = 1; i <= slen; i++) {
            for (int j = 1; j <= tlen; j++) {
                dp[i][j] = max (dp[i][j-1], dp[i-1][j]); //just like LCS
                for (int c = 0; c <= i; c++) {
                    if (c >= k) dp[i][j] = max (dp[i][j], dp[i-c][j-c] + c); //how many in sequence previously
                    if (s[i-c] != t[j-c]) break;
                }
            }
        }
        printf ("%d\n", dp[slen][tlen]);
    }
    return 0;
}
