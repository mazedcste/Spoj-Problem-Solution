#include <bits/stdc++.h>
using namespace std;
#define LL long long
double cosine (int a, int b, int c) {
	return (double) (( a*a + b*b - c*c ) / (2.0 * a * b)); //cosine law
}
int main ()
{
    int n, tc;
    scanf (" %d", &tc);

    while (tc--) {
        int AB, BC, AC, AD, BD, CD;
		double cos1, cos2, cos3;

        scanf(" %d %d %d %d %d %d", &AB, &AC, &AD, &BC, &BD, &CD);
        //3 ANGLE IN D POINT
        cos1 = cosine(AD, BD, AB);
		cos2 = cosine(BD, CD, BC);
		cos3 = cosine(CD, AD, AC);
		double temp = AD * BD * CD * sqrt( 1 + 2 * cos1 * cos2 * cos3 - cos1*cos1 - cos2*cos2 - cos3*cos3) / 6.0;
        printf("%.4f\n", temp);
    }
    return 0;
}
