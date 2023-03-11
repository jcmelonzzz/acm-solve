#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define base 123
#define mod 21132878718494

const int maxn = 1e4 + 10;
ull Hash[maxn];
char op[1510];
ull cnt;

int main()
{
    ios::sync_with_stdio(false);
    
    int T;
    int ans = 0;
    cin >> T;
    int t = T;
    memset(Hash,0,sizeof(Hash));
    while(T--){
        cnt = 0;//预先存储
        cin >> op;
        int len = strlen(op);
        for(int i=0;i<len;i++){
            cnt = ((cnt * base % mod) + op[i] - '0' + 1)%mod;
        }
        Hash[T] = cnt;
    }
    sort(Hash,Hash+t);
    for(int i=0;i<t;i++){
        if(Hash[i] != Hash[i+1])ans++;
    }
    cout << ans << endl;
}