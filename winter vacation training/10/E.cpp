#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 1e5 + 10;
ll n,m,p;

ll a[maxn],t[4*maxn],lazy_jia[4*maxn],lazy_cheng[maxn*4];
// ll ans;
// void push_up(int l,int r,int d){
//     t[d] = t[2*d] + t[2*d+1];
// }
void down_jia(ll d,ll l,ll r,ll k){
    lazy_jia[d] += k;
    t[d] += k*(r-l+1);
    t[d] %= p;
}
void down_cheng(ll d,ll l,ll r,ll k){
    lazy_cheng[d] *= k;
    t[d] *= (r - l + 1)*k;
    t[d] %= p;
}
void push_down_jia(ll d,ll l,ll r){
    ll mid = (l + r)>>1;
    down_jia(2*d,l,mid,lazy_jia[d]);
    down_jia(2*d+1,mid+1,r,lazy_jia[d]);
    lazy_jia[d] = 0;
}
void push_down_cheng(ll d,ll l,ll r){
    ll mid = (l + r)>>1;
    down_cheng(2*d,l,mid,lazy_cheng[d]);
    down_cheng(2*d+1,mid+1,r,lazy_cheng[d]);
    lazy_cheng[d] = 1;
}
void bulid(ll l,ll r,ll d){
    if(l==r){
        t[d]=a[l];
        return;
    }
    ll mid = (l+r)>>1;//>>1相当于除以2
    bulid(l,mid,2*d);
    bulid(mid+1,r,2*d+1);
    t[d] = t[2*d] + t[2*d+1];
}//建立树
void update_cheng(ll d,ll dl,ll dr,ll x,ll y,ll k){
    if(x <= dl&&dr <= y){
        t[d] *= (dr - dl + 1) * k;
        t[d] %= p;
        lazy_cheng[d] *= k;
        return ;
    }
    push_down_cheng(d,dl,dr);

    ll mid = (dl + dr)>>1;
    if(x <= mid)update_cheng(2*d,dl,mid,x,y,k);
    if(mid < y)update_cheng(2*d+1,mid+1,dr,x,y,k);

    t[d] = t[2*d] + t[2*d+1];
}
void update_jia(ll d,ll dl,ll dr,ll x,ll y,ll k){
    // if(dl == dr&&dl == x){
    //     t[d] += k;
    //     return;
    // }
    if(x <= dl&&dr <= y){
        t[d] += (dr - dl + 1) * k;
        lazy_jia[d] += k;
        t[d] %= p;
        return ;
    }
    push_down_jia(d,dl,dr);

    ll mid = (dl + dr)>>1;
    if(x <= mid)update_jia(2*d,dl,mid,x,y,k);
    if(mid < y)update_jia(2*d+1,mid+1,dr,x,y,k);

    t[d] = t[2*d] + t[2*d+1];
}
ll query(ll d,ll dl,ll dr,ll l,ll r){
    if(l == dl&&dr == r)return t[d];
    if(l > dr||r < dl)return 0;
    ll mid = (dl + dr)>>1;
    push_down_cheng(d,dl,dr);
    push_down_jia(d,dl,dr);

    if(r <= mid)return query(2*d,dl,mid,l,r);
    else if(l > mid)return query(2*d+1,mid+1,dr,l,r);
    else return query(2*d,dl,mid,l,mid) + query(2*d+1,mid+1,dr,mid+1,r);
    // if(mid >= r)query(2*d,dl,mid,l,r);
    // if(mid <= l)query(2*d+1,mid+1,dr,l,r);
    // else{
    //     query(2*d,dl,mid,l,mid);
    //     query(2*d+1,mid+1,dr,mid+1,r);
    // }
}//求和
int main()
{
    while(scanf("%lld%lld%lld",&n,&m,&p)!=EOF){
        memset(lazy_jia,0,sizeof(lazy_jia));
        // memset(lazy_cheng,-1,sizeof(lazy_cheng));
        for(int i=1;i<=4*n;i++){
            lazy_cheng[i] = 1;
        }
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        bulid(1,n,1);
        for(int i=1;i<=m;i++){
            ll op,x,y,k;
            scanf("%lld",&op);
            if(op==1){
                scanf("%lld%lld%lld",&x,&y,&k);
                update_cheng(1,1,n,x,y,k);
            }else if(op == 2){
                scanf("%lld%lld%lld",&x,&y,&k);
                update_jia(1,1,n,x,y,k);
            }else{
                scanf("%lld%lld",&x,&y);
                // ans = query(1,1,n,x,y);
                printf("%lld\n",query(1,1,n,x,y)); 
            }
        }
    }
}