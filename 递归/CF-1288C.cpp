#include<iostream>
#include<cmath>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
ll pow(ll a, ll b){
    ll ans = 1;
    while(b --){
        ans = (ans * a) % MOD;
    }
    return ans;
}
ll mem[1005][1005][15];
ll f(ll cur, ll n, ll m){
    n -= cur;
    cur = 0;
    if(mem[cur][n][m]) return mem[cur][n][m];
    if(m == 0){
        return 0;
    }
    if(m == 1) return n - cur + 1;
    ll ans = 0;
    for(int i=cur; i<=n; i ++){
        ans = (ans + (f(i, n, m - 1)  % MOD)) % MOD;
    }
    return mem[cur][n][m] = ans % MOD;
}
int main(void){
    /*
    开始放进去的数字很关键 后面的数字都是按照其作为依据的 同时还需要知道下面一条的最后升到 多少也很关键
    开始的数字组合有多少种？
    (1 + n ) * n / 2
    最后一个数字的取值呢？n
    //假设现在下面是a 上面是b 中间是c 长度为m
    上面：长度为m-1的 方案 (b - c + 1) ^ (m-1)
    下面：长度为m-2的 方案 (c - a + 1) ^ (m-2)
    现在要计算所有的a的和

    */

    ll n, m;
    cin >> n >> m;
    //cout << f(1, n, m) << "!" << endl;
    if(m == 1){
        cout << (1 + n) * n / 2 << endl;
        return 0;
    }
    ll ans = 0;
    for(ll a = 1; a <= n; a ++){
        for(ll b = a; b <= n; b ++){
            ans = (ans + (f(b, n, m - 1) * f(1, a, m - 1)) % MOD) % MOD;
            //cout << ans << endl;
        }
    }

    cout << ans << endl;

    return 0;
}