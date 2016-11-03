#include <bits/stdc++.h>
using namespace std;
int ara[60005];
int seg[140000];

void build (int at, int L, int R) {
    if (L == R) {
        seg[at] = ara[L];
        return;
    }
    int mid = (L+R) /2;
    build (2*at, L, mid);
    build (2*at+1, mid+1, R);
    seg[at] = seg[2*at] & seg[2*at+1];
}
int query (int at, int L, int R, int l, int r) {
    if (L > r || R < l) return -1;
    if (L >= l && R <= r) return seg[at];
    int mid = (L+R) /2;
    int x = query (2*at, L, mid, l, r);
    int y = query (2*at+1, mid+1, R, l, r);
    return x&y;
}
int main ()
{
    int tc, n, k;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf (" %d", &ara[i]);
            ara[i+n] = ara[i];
            ara[i+2*n] = ara[i];
        }

        build (1, 1, 3*n);
        for (int i = n+1; i <= 2*n; i++) {
            int L = max (1, i-k);
            int R = min (3*n, i+k);
            if (i == 2*n) {printf ("%d\n", query (1, 1, 3*n, L, R)); break;}
            printf ("%d ", query (1, 1, 3*n, L, R));
        }
    }
    return 0;
}
