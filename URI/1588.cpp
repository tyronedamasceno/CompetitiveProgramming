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

struct Time
{
	string nome;
	int pontos, vitorias, gols, id;
};

bool cmp(Time a, Time b)
{
	if (a.pontos != b.pontos) return a.pontos > b.pontos;
	if (a.vitorias != b.vitorias) return a.vitorias > b.vitorias;
	if (a.gols != b.gols) return a.gols > b.gols;
	return a.id < b.id;
}

Time times[1234];

map <string, int> ids;
int m, n, t, g1, g2, aux1, aux2;
string aux, t1, t2;

int main()
{
	cin >> t;

	while(t--)
	{
		ids.clear();
		cin >> m >> n;

		rep(i, 0, m)
		{
			cin >> aux;
			ids[aux] = i;
			times[i].nome = aux;
			times[i].pontos = times[i].gols = times[i].vitorias = 0;
			times[i].id = i;
		}

		rep(i, 0, n)
		{
			cin >> g1 >> t1 >> g2 >> t2;
			aux1 = ids[t1];
			aux2 = ids[t2];

			times[aux1].gols += g1;
			times[aux2].gols += g2;

			if (g1 > g2)
			{
				times[aux1].vitorias++;
				times[aux1].pontos += 3;
			} else if (g1 < g2)
			{
				times[aux2].vitorias++;
				times[aux2].pontos += 3;
			} else
			{
				times[aux1].pontos++;
				times[aux2].pontos++;
			}
		}

		sort(times, times+m, cmp);

		rep(i, 0, m) cout << times[i].nome << endl;


	}

	return 0;
}