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
	int n, c, aux, ult;
	int t = 1;
	in2(n, c);

	in1(ult);

	rep(i, 1, n)
	{
		in1(aux);
		if ((aux - ult) <= c)
		{
			t++;
			ult = aux;
		} else
		{
			t = 1;
			ult = aux;
		}
	}

	cout << t << endl;


	return 0;
}