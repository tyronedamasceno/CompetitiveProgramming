/*
	
	MARATONA SBC - 2016
	PROBLEMA G

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

int tab[502][502];

int main()
{
	clr(tab, 0);
	ll br, pr = 0;  // PR = 1, BR = 2
	int n, p, a, b;
	bool cPR, cBR;

	in2(n, p);

	rep(i, 0, p)
	{
		in2(a, b);
		tab[a][b] = 1;
	}
	rep(i, 0, p)
	{
		in2(a, b);
		tab[a][b] = 2;
	}


	rep(i, 1, n+1)
	{
		rep(j, 1, n+1)
		{
			cPR = cBR = false;

			while(!(cPR && cBR))
			{
				int dist = min((p-i), (p-j));
				rep(k, 0, dist)
				{
					
				}



			}

		}
	}




	return 0;
}
