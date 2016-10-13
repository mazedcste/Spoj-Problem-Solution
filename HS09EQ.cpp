#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define read(f)  freopen(f,"r",stdin)
#define write(f) freopen(f,"w",stdout)
#define pb push_back
#define mkp make_pair

int main ()
{
    //ios::sync_with_stdio(0); cin.tie(0); //read("in.txt");
    int tc;
    cin >> tc;
    LL n, res;
    while (tc--) {
        cin >> n;
        res = 0;
        for (LL i = 0; i*i*i*i <= n; i++) {
            for (int j = 0; j*j*j <= n; j++) {
                LL temp = n - i*i*i*i - j*j*j;
                if (temp >= 0) res += (sqrt (temp) + 1);
            }
        }
        cout << res << endl;
    }
    return 0;
}
