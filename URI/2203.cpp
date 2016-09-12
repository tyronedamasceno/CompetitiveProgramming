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
	int x1, y1, x2, y2, v, r1, r2;

	while (cin >> x1 >> y1 >> x2 >> y2 >> v >> r1 >> r2)
	{
		double dist = hypot((double)(x1-x2), (double)(y1-y2)) + v + v/2.0;
		if (r1 + r2 >= dist) cout << "Y" << endl;
		else cout << "N" << endl;
	}


	return 0;
}