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
	stringstream ss;
	string a, b;
	ll p, q;

	while (cin >> a >> b)
	{
		if (a == "0" && b == "0") break;

		p = (a[0] - '0');
		q = (b[0] - '0');

		while(a.size() > 1)
		{
			ss.clear();
			p = 0;
			rep(i, 0, a.size()) p += (a[i] - '0');
			ss << p;
			a.clear();
			ss >> a;
		}

		while(b.size() > 1)
		{
			ss.clear();
			q = 0;
			rep(i, 0, b.size()) q += (b[i] - '0');
			ss << q;
			b.clear();
			ss >> b;
		}

		if (p > q) cout << 1 << endl;
		else if (p < q) cout << 2 << endl;
		else cout << 0 << endl;

	}


	return 0;
}