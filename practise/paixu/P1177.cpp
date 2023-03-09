#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int a[maxn];
int n;

void Quick_sort(int l,int r){
    int mid = a[(l + r)/2];
    int nl = l,nr = r;
    while(nl <= nr){
        while(a[nl] < mid)nl ++;
        while(a[nr] > mid)nr --;
        if(nl <= nr){
            swap(a[nl],a[nr]);
            nr--;
            nl++;
        }
    }
    if(l < nr)Quick_sort(l,nr);
    if(nl < r)Quick_sort(nl,r);
}

void solve()
{
    Quick_sort(1,n);
    for(int i=1;i<=n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n){
        for(int i=1;i<=n;i++)
            cin >> a[i];
        solve();
    }
    return 0;
}