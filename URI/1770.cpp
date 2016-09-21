#include <bits/stdc++.h>

using namespace std;

int m, k, ans, aux;
bool f;
map <int, int> a;
set <int> b;

int main()
{
	while(cin >> m >> k)
	{
		ans = 0;
		a.clear();
		b.clear();
		f = true;
		for (int i = 1; i <= m; ++i)
		{
			cin >> aux;
			a[i] = aux;
		}
		for (int i = 0; i < k; ++i)
		{
			cin >> aux;
			b.insert(aux);
			ans += a[aux];
			if(b.size() == m)
			{
				cout << ans << endl;
				f = false;
				break;
			}
		}
		if (f) cout << -1 << endl;
	}
	return 0;
}