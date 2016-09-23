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

map <int, vi> m;
vi aux;
int n, v, at;
bool f;

int main()
{

	rep(k, 1, 31)
	{
		aux.clear();
		at = 0;
		for(int i = k; i >= 1; i--)
		{
			for(int j = 0; j < i; j++)
			{
				aux.pb(at + i);
				at += i;
			}
		}
		m[k] = aux;
	}

	while(cin >> n >> v && (n || v))
	{
		f = false;
		for (int i = 1; i <= v; i++)
		{
			if (find(m[i].begin(), m[i].end(), n) != m[i].end())
			{
				cout << "possivel" << endl;
				f = true;
				break;
			}
		}
		if (!f) cout << "impossivel" << endl;
	}

	return 0;
}