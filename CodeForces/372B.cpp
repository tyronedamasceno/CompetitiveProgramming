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
#define clr(a, x) memset(a, x, sizeof(x))
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define F first
#define S second
#define in1(a) scanf("%d", &a)
#define in2(a, b) scanf("%d %d", &a, &b)
#define in3(a, b, c) scanf("%d %d %d", &a, &b, &c)

int let[26];
bool conf()
{
	rep(i, 0, 26) if(let[i] >= 2) return false;
	return true;
}


int main()
{
	string s;
	cin >> s;
	int n = s.size();

	if (n < 26)
	{
		cout << -1 << endl;
		return 0;
	}

	rep(i, 25, n)
	{
		memset(let, 0, sizeof(let));

		rep(j, i-25, i+1)
			if (s[j] != '?') let[(s[j] - 'A')]++;

		if (conf())
		{
			int aux = 0;

			rep(j, i-25, i+1)
				if(s[j] == '?')
				{
					while(let[aux]) aux++;
					s[j] = ('A' + aux);
					aux++;
				}

			rep(j, 0, n) if (s[j] == '?') s[j] = 'A';
			cout << s << endl;
			return 0;
		}
	}

	cout << -1 << endl;
	

	return 0;
}