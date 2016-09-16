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

ll toDec(string s)
{
	ll aux = 0;
	reverse(s.begin(), s.end());

	rep(i, 0, s.size())
	{
		if (s[i] >= '0' && s[i] <= '9') aux += (s[i] - '0')*pow(16, i);
		else aux += (s[i] - 'a' + 10)* pow(16, i);
	}
	return aux;
}

string toHex(ll n)
{
	string aux = "";
	while(n)
	{
		int k = n % 16;
		if (k < 10) aux += (k + '0');
		else aux += (k - 10 + 'a');
		n /= 16;
	}
	reverse(aux.begin(), aux.end());
	return aux;
}

int main()
{
	string r, g, b, ans;
	ll ri, gi, bi, ansi;

	cin >> r >> g >> b;

	ri = toDec(r);
	gi = toDec(g);
	bi = toDec(b);

	ansi = 1 + (ri/gi)*(ri/gi) + ((ri/gi)*(ri/gi))*((gi/bi)*(gi/bi));
	ans = toHex(ansi);

	cout << ans << endl;

	return 0;
}