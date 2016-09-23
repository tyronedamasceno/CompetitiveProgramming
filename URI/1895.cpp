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
	int n, t, l, k;
	int a, b;
	a = b = 0;

	cin >> n >> t >> l;

	rep(i, 0, n-1)
	{
		cin >> k;
		if (abs(k-t) <= l)
		{
			if(!(i % 2)) a += abs(k-t);
			else b += abs(k-t);
			t = k;
		}
	}

	cout << a << " " << b << endl;


	return 0;
}