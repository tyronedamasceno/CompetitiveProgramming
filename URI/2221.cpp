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
	int t;

	cin >> t;

	while(t--)
	{
		int bonus, a1, d1, n1, a2, d2, n2, p1, p2;
		cin >> bonus >> a1 >> d1 >> n1 >> a2 >> d2 >> n2;
		p1 = (a1+d1)/2;
		p2 = (a2+d2)/2;
		if (!(n1 % 2)) p1 += bonus;
		if (!(n2 % 2)) p2 += bonus;
		if (p1 > p2) cout << "Dabriel" << endl;
		else if (p1 == p2) cout << "Empate" << endl;
		else cout << "Guarte" << endl;
	}


	return 0;
}