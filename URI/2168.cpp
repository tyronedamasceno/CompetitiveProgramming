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

int mat[105][105];
char ans[105][105];

int main()
{
	int n;

	cin >> n;

	rep(i, 0, n+1)
		rep(j, 0, n+1)
			cin >> mat[i][j];

	rep(i, 0, n)
	{
		rep(j, 0, n)
		{
			int k = 0;
			if (mat[i][j]) k++;
			if (mat[i+1][j]) k++;
			if (mat[i][j+1]) k++;
			if (mat[i+1][j+1]) k++;
			if (k >= 2) cout << "S";
			else cout << "U";
		}
		cout << endl;
	}


	return 0;
}