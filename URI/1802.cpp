#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef stack <int> pil;
typedef queue <int> fil;
typedef pair <int, int> ii;
typedef vector <ii> vii;

#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = a; i < b; i++)
#define clr(a, x) memset(a, x, sizeof x)
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define F first
#define S second
#define in1(a) scanf("%d", &a)
#define in2(a, b) scanf("%d %d", &a, &b)
#define in3(a, b, c) scanf("%d %d %d", &a, &b, &c)

int main()
{
	int n, aux, p;
	vi a, b, c, d, e;
	vi val;

	cin >> n; rep(i, 0, n) {in1(aux); a.pb(aux);}
	cin >> n; rep(i, 0, n) {in1(aux); b.pb(aux);}
	cin >> n; rep(i, 0, n) {in1(aux); c.pb(aux);}
	cin >> n; rep(i, 0, n) {in1(aux); d.pb(aux);}
	cin >> n; rep(i, 0, n) {in1(aux); e.pb(aux);}

	cin >> p;

	rep(i, 0, sz(a))
		rep(j, 0, sz(b))
			rep(k, 0, sz(c))
				rep(l, 0, sz(d))
					rep(m, 0, sz(e))
					{
						aux = (a[i] + b[j] + c[k] + d[l] + e[m]);
						val.pb(aux);
					}

	sort(val.rbegin(), val.rend());

	ll ans = 0;

	rep(i, 0, p) ans += val[i];

	cout << ans << endl;



	return 0;
}