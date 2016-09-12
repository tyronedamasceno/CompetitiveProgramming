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
#define all(a) (a.begin(), a.end())
#define sz(a) (int)a.size()
#define F first
#define S second
#define in1(a) scanf("%d", &a)
#define in2(a, b) scanf("%d %d", &a, &b)
#define in3(a, b, c) scanf("%d %d %d", &a, &b, &c)

bool comp(ii a, ii b)
{
	if (a.F > b.F) return true;
	if (a.F < b.F) return false;
	return a.S < b.S;
}

int main()
{
	int a, v, t = 0;	
	int o, d;
	while (cin >> a >> v)
	{
		if (!a && !v) break;

		vii k(105);
		rep(i, 0, a)
		{
			k[i].F = 0;
			k[i].S = i;
		}

		rep(i, 0, v)
		{
			in2(o, d);
			o--; d--;

			k[o].F++; k[d].F++;
		}

		sort(k.begin(), k.begin()+a, comp);
		
		cout << "Teste " << ++t << endl;
		for (int i = 0; k[i].F == k[0].F; i++)
			cout << k[i].S + 1 << " ";

		cout << "\n\n";

	}

	return 0;
}