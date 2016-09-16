#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef map <int, int> mii;
typedef map <string, int> msi;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(a, k) memset(a, k, sizeof(a))
#define rep(i, a, b) for(int i = a; i < b; i++)
#define in1(a) scanf("%d", &a)
#define in2(a, b) scanf("%d %d", &a, &b)
#define in3(a, b, c) scanf("%d %d %d", &a, &b, &c)

int main()
{
	int n, t = 0;
	while (cin >> n && n)
	{
		cout << "Teste " << ++t << endl;
		int a, b, k = 0;
		rep(i, 0, n)
		{
			cin >> a >> b;
			k += a;
			k -= b;
			cout << k << endl;
		}
		cout << endl;
	}		
	return 0;
}