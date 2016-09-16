/*
	
	MARATONA SBC - 2016
	PROBLEMA C

*/

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

int orig[2][4];
int dest[2][4];

int solve()
{
	
}

int main()
{
	rep(i, 0, 2) rep(j, 0, 4) cin >> orig[i][j];
	rep(i, 0, 2) rep(j, 0, 4) cin >> dest[i][j];


	cout << solve() << endl;
	return 0;
}