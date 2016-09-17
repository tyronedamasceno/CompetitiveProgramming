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
	int x, y, n, aux, t = 0;
	vi v;

	while (cin >> x >> y >> n && (x && y && n))
	{
		v.clear();
		rep(i, 0, n)
		{
			cin >> aux;
			v.pb(aux);
		}
		sort(v.rbegin(), v.rend());

		rep(i, 0, n)
		{
			if (x < y) x += v[i];
			else y += v[i];
		}

		cout << "Teste " << ++t << endl;
		if (x == y) cout << "S" << endl;
		else cout << "N" << endl;

		cout << endl;

	}

	return 0;
}