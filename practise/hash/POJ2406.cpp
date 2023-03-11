#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define ull unsigned long long
#define base 131

const int maxn = 1e6 + 10;
ull Hash[maxn];
ull p[maxn];
char a[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    p[0] = 1;
    for(int i=1;i<=maxn;i++)p[i] = p[i-1] * base;
    while(cin >> a && a[0] != '.'){
        int len = strlen(a);
        // for(int i=1;i<=len;i++){
        //     int flag = 1;
        //     if(len % i != 0)continue;
        //     else{
        //         for(int j=0;j<len;j++){
        //             if(a[j%i] != a[j]){
        //                 flag = 0;
        //                 break;
        //             }
        //         }
        //         if(flag){
        //             cout << len / i << endl;
        //             break;
        //         }
        //     }
        // }//不用哈希的做法
        //使用哈希
        Hash[0] = a[0] - '\0' + 1;
        for(int i=1;i<len;i++){
            Hash[i] = Hash[i-1] * base + a[i] - '\0' + 1;
        }//处理哈希值
        for(int i=1;i<=len;i++){
            int flag = 1;
            if(len % i)continue;
            else{
                for(int j=2*i-1;j<len;j+=i){
                    if(Hash[i-1] != Hash[j] - Hash[j-i]*p[i]){
                        flag = 0;
                        break;
                    }
                }
                if(flag){
                    cout << len / i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}