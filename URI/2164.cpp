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
	double a, b, c;

	a = (1.0 + sqrt(5.0)) / 2.0;
	b = (1.0 - sqrt(5.0)) / 2.0;

	int n;
	cin >> n;	

	c = (pow(a, n) - pow(b, n)) / sqrt(5.0);

	cout << fixed << setprecision(1) << c << endl;

	return 0;
}
