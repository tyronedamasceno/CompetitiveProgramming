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

map <int, bool> m;
map <int, bool>::iterator it;

int main()
{
	int n, aux;

	cin >> n;

	rep(i, 0, n)
	{
		in1(aux);
		m[aux] = true;
	}

	int tam = m.size();

	if (tam == 1 || tam == 2) cout << "YES" << endl;
	else if (tam >= 4) cout << "NO" << endl;
	else
	{
		vi v;
		for(it = m.begin(); it != m.end(); it++) v.pb(it->F);
		if (2*v[1] == v[0] + v[2]) cout << "YES" << endl;
		else cout << "NO" << endl;

	}


	return 0;
}