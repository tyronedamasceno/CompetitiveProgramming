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

bool dp[10001][101];
int joias[101];

bool subset_sum(int v[], int n, int t) {
    int i, j;
    
    for (j = 0; j <= n; j++) dp[0][j] = true;
    for (i = 1; i <= t; i++) dp[i][0] = false;
   
    for (j = 1; j <= n; j++)
        for (i = 1; i <= t; i++) {
            dp[i][j] = dp[i][j-1];
            if ( i >= v[j] && dp[i-v[j]][j-1] )
                dp[i][j] = true;
        }

    return dp[t][n];
}


int main()
{

    int n, i, x, y, sum, t = 1;

    while (true)
    {
        in3(x, y, n);
        
        if ( x == 0 && y == 0 && n == 0 )
            break;
            
        for (sum = 0, i = 1; i <= n; i++) 
        {
            in1(joias[i]);
            sum += joias[i];
        }
            
        printf("Teste %d\n", t++);
        if ( (x + y + sum) % 2 || min(x, y) + sum < max(x, y) ) 
        {
            printf("N\n\n");
            continue;
        }
        
        printf("%c\n\n", subset_sum(joias, n, (x+y+sum)/2 - x) ? 'S' : 'N');
        
    }
    
    return 0;
}
