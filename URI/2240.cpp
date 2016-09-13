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

#define MAX 10004

vi a[MAX], b[MAX];
int nA, nB;
int q, esq, cent, dir, raizA, raizB, maiorA, maiorB, cont;
int visA[MAX], visB[MAX];

void dfsA(int v)
{
	visA[v] = 1;
	rep(i, 0, a[v].size())
	{
		if (!visA[a[v][i]])
		{
			cont++;
			dfsA(a[v][i]);
		}
	}
}
void dfsB(int v)
{
	visB[v] = 1;
	rep(i, 0, b[v].size())
	{
		if (!visB[b[v][i]])
		{
			cont++;
			dfsB(b[v][i]);
		}
	}
}


int main()
{
	raizA = raizB = maiorA = maiorB = cont = 0;
	clr(visA, 0); clr(visB, 0);

	cin >> nA;
	rep(i, 0, nA)
	{
		in3(q, esq, cent);
		if (cent) a[q].pb(cent);
	}
	cin >> nB;
	rep(i, 0, nB)
	{
		in3(q, cent, dir);
		if (cent) b[q].pb(cent);
	}

	rep(i, 0, nA+1)
	{
		if(!visA[i])
		{
			cont = 1;
			dfsA(i);
			maiorA = max(maiorA, cont);
		}
	}
	rep(i, 0, nB+1)
	{
		if(!visB[i])
		{
			cont = 1;
			dfsB(i);
			maiorB = max(maiorB, cont);
		}
	}

	clr(visA, 0); clr(visB, 0);
	cont = 1;
	dfsA(1);
	raizA = cont;
	cont = 1;
	dfsB(1);
	raizB = cont;

	int ans = nA + nB - max(min(raizA, maiorB), min(raizB, maiorA));
	cout << ans << endl;

	return 0;
}