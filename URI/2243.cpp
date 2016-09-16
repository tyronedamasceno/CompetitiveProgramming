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

int main()
{
	int n;
	cin >> n;

	vi m(n), a(n), b(n);

	rep(i, 0, n)
		cin >> m[i];

	a[0] = b[n-1] = 1;

	for (int i = 1; i < n; i++)
		if (m[i] > a[i-1]) a[i] = a[i-1] + 1;
		else a[i] = m[i];

	for (int i = n-2; i >= 0; i--)
		if (m[i] > b[i+1]) b[i] = b[i+1] + 1;
		else b[i] = m[i];

	int big = 0, aux;

	rep(i, 0, n)
	{
		aux = min(a[i], b[i]);
		big = max(big, aux);
	}

	cout << big << endl;


	return 0;
}