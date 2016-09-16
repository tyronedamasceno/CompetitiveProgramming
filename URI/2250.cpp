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

struct Jog
{
	string nome;
	int maior, menor, total;
	int pos;
};

bool cmp(Jog a, Jog b)
{
	if (a.total != b.total) return a.total > b.total;
	return a.nome < b.nome;
}



int main()
{
	int n, t = 0;
	while (cin >> n && n)
	{
		vector <Jog> v;
		string auxNome;
		rep(q, 0, n)
		{
			Jog aux;
			int k;
			aux.total = 0;
			aux.maior = -1;
			aux.menor = 9999999;
			cin >> auxNome;
			aux.nome = auxNome;
			rep(i, 0, 12)
			{
				in1(k);
				aux.total += k;
				aux.maior = max(aux.maior, k);
				aux.menor = min(aux.menor, k);
			}
			aux.total -= (aux.maior + aux.menor);
			v.pb(aux);
		}
		sort(v.begin(), v.end(), cmp);
		cout << "Teste " << ++t << endl;
		rep(b, 0, v.size())
		{
			if (b == 0) v[b].pos = 1;
			else
				if (v[b].total == v[b-1].total) v[b].pos = v[b-1].pos;
				else v[b].pos = b+1;
			
			cout << v[b].pos << " " << v[b].total << " " << v[b].nome << endl;
		}
		cout << endl;
	}		
	
	return 0;
}