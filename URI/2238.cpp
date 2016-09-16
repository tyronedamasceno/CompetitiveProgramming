/*
	
	MARATONA SBC - 2016
	PROBLEMA D

*/

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
	ll a, b, c, d;

	cin >> a >> b >> c >> d;

	vi div;
	int k = sqrt (c) + 3;
	rep(i, 2, k)
	{
		if (c % i == 0)
		{
			div.pb(i);
			div.pb(c/i);
		}
	}

	sort(all(div));

	rep(i, 0, div.size())
	{
		if ((div[i] % a) == 0 && (div[i] % b) != 0 && (c % div[i]) == 0 && (d % div[i]) != 0)
		{
			cout << div[i] << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}