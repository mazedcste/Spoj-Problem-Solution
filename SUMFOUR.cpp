#include <bits/stdc++.h>
using namespace std;
#define N 4001
int p[N*N];
int a[N], b[N], c[N], d[N], cnt;
int bs (int x) {
    int lo = 0, hi = cnt-1, mid;
    while (lo <= hi) {
        mid = (lo+hi) >> 1;
        //cout << lo << " " << hi << endl;
        if (p[mid] == x) {
            int cn = 0;
            while (mid >= 0 && p[mid] == x) mid--;
            mid++;
            while (mid < cnt && p[mid] == x) mid++, cn++;
            return cn;
        }
        if (p[mid] < x) {
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
    return 0;
}
int main ()
{
    //freopen ("in.txt", "r", stdin);
    int n, x, ans = 0, pos;
    scanf (" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf (" %d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            p[cnt++] = a[i] + b[j];
        }
    }
    sort (p, p+cnt);
//    for (int i = 0; i < cnt; i++) cout << p[i] << " ";
//    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += bs(-(c[i] + d[j]));
        }
    }
    printf ("%d\n", ans);
    return 0;
}


