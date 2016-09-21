#include <bits/stdc++.h>

using namespace std;

int m, k, ans, aux, pp;
bool f;
map <int, int> a;
set <int> b;

int main()
{
	while(scanf("%d %d", &m, &k) != EOF)
	{
		ans = 0;
		a.clear();
		b.clear();
		f = true;
		for (int i = 1; i <= m; ++i)
		{
			scanf("%d", &aux);
			a[i] = aux;
		}
		for (int i = 0; i < k; ++i)
		{
			scanf("%d", &aux);
			b.insert(aux);
			ans += a[aux];
			if(b.size() == m && f)
			{
				pp = ans;
				f = false;
			}
		}
		if (f) printf("%d\n", -1);
		else printf("%d\n", pp);
	}
	return 0;
}