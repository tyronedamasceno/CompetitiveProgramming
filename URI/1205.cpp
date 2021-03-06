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

int n, m, k, u, v, qt, aux, orig, dest;
double p;

map <int, int> sold;
vi adj[1003];
int dist[1003];
int vis[1003];

int dijkstra(int o, int d)
{
	rep(i, 0, 1003)
	{
		dist[i] = 99999999;
		vis[i] = 0;
	}

	dist[o] = sold[o];

	priority_queue < ii, vii, greater<ii> > pq;

	pq.push(mp(dist[o], o)); // distancia / vertice atual

	while(!pq.empty())
	{
		ii p = pq.top();
		int at = p.S;
		pq.pop();

		if (!vis[at])
		{
			vis[at] = 1;

			for(int i = 0; i < adj[at].size(); i++)
			{
				int prox = adj[at][i];
				int custo = sold[prox];
				
				if (dist[at] + custo < dist[prox])
				{
					dist[prox] = dist[at] + custo;
					pq.push(mp(dist[prox], prox));
				}
			}


		}

	}

	return dist[d];

}

int main()
{

	while (cin >> n >> m >> k >> p)
	{
		rep(i, 0, 1003) adj[i].clear();
		sold.clear();

		rep(i, 0, m)
		{
			in2(u, v);
			u--; v--;
			adj[u].pb(v);
			adj[v].pb(u);
		}

		in1(qt);
		rep(i, 0, qt)
		{
			in1(aux);
			aux--;
			sold[aux]++;
		}

		in2(orig, dest);
		orig--; dest--;
		int ans = dijkstra(orig, dest);

		if (ans > k)
		{
			cout << fixed << setprecision(3) << 0.0 << endl;
		}
		else cout << fixed << setprecision(3) << pow(p, ans) << endl;

	}

	return 0;
}