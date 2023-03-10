#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define base 107//取整容易只因
#define ull unsigned long long

const int maxn = 4e5 + 10;
ull Hash_1[maxn];
ull Hash_2[maxn];
ull p[maxn];
char a[maxn],b[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    p[0] = 1;
    for(int i=1;i<=maxn;i++)p[i] = p[i-1] * base;
    while(cin >> a >> b){
        // vector<int> ans;
        
        int len = strlen(a);
        Hash[0] = 0;
        for(int i=0;i<len;i++)Hash[i+1] = Hash[i] * base + a[i] - 'a' + 1;//正方向
        int l=1,r=len;
        for(;l<=len;){
            if(Hash[l] == Hash[len] - Hash[r-1]*p[l])cout << l << " ";
            l ++,r --;
        }
        cout << endl;
        // for(int i=0;i<ans.size();i++){
        //     if(i < ans.size()-1)cout << ans[i] << " ";
        //     else cout << ans[i] << endl;
        // }
    }
    return 0;
}