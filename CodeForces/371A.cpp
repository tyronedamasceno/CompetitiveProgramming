#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef map <int, int> mii;
typedef map <string, int> msi;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(a, k) memset(a, k, sizeof(a))
#define rep(i, a, b) for(int i = a; i < b; i++)
#define in1(a) scanf("%d", &a)
#define in2(a, b) scanf("%d %d", &a, &b)
#define in3(a, b, c) scanf("%d %d %d", &a, &b, &c)

int main()
{
	ll l1, r1, l2, r2, k, ans = 0, a, b;		

	cin >> l1 >> r1 >> l2 >> r2 >> k;

	a = max(l1, l2);
	b = min(r1, r2);

	ans = (b - a + 1);
	if (k >= a && k <= b) ans--;

	ans = max(0ll, ans);

	cout << ans << endl;

	return 0;
}