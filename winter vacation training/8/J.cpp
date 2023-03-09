#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n,m;
int lu_sum = 0;//路线总数
int lu_all = 0;//权值综合
int id[maxn];//序号
struct lu
{
    int u,v;
    int cost;
    //bool operator <(const lu& t)const{
    //    return cost < t.cost;
    //}
}p[maxn];
bool cmp(lu a,lu b){
    return a.cost < b.cost;
}//也可以用重载运算符
int find(int x){
    if(id[x] != x)id[x] = find(id[x]);
    return id[x];
}
void solve(){
    sort(p+1,p+1+m);
    for(int i=1;i<=n;i++)id[i] = i;
    for(int i=1;i<=m;i++){
        if(find(p[i].u)!=find(p[i].v)){
            id[find(p[i].u)] = find(p[i].v);
            lu_sum ++;
            lu_all += p[i].cost;
            if(lu_sum == n-1)break;
        }
    }
}