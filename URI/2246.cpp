/*
	
	MARATONA SBC - 2016
	PROBLEMA L

*/

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

int h, l, cont;
int m[205][205];
int vis[205][205];

vi v;

void dfs(int i, int j)
{
	if (!vis[i][j])
	{
		vis[i][j] = 1;

		if (j < l-1 && m[i][j] == m[i][j+1] && !vis[i][j+1])
		{
			cont++;
			dfs(i, j+1);
		}
		if (j > 0 && m[i][j] == m[i][j-1] && !vis[i][j-1])
		{
			cont++;
			dfs(i, j-1);
		}
		if (i < h-1 && m[i][j] == m[i+1][j] && !vis[i+1][j])
		{
			cont++;
			dfs(i+1, j);
		}
		if (i > 0 && m[i][j] == m[i-1][j] && !vis[i-1][j])
		{
			cont++;
			dfs(i-1, j);
		}
	}
}

int main()
{
	cin >> h >> l;

	rep(i, 0, h) rep(j, 0, l) cin >> m[i][j];

	rep(i, 0, h)
		rep(j, 0, l)
			if (!vis[i][j])
			{
				cont = 1;
				dfs(i, j);
				v.pb(cont);
			}

	sort(v.begin(), v.end());

	cout << v[0] << endl;
	return 0;
}