#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
ll add(ll a, ll b){
    ll cnt = a + b;
    if(cnt >= MOD) cnt -= MOD;
    return cnt;
}
ll mul(ll a, ll b){
    ll ans = a * 1ll * b % MOD;
    return ans;
}
ll quick_pow(ll base, ll n){
    ll ans = 1;
    while(n){
        if(n & 1) ans = mul(ans, base);
        base = mul(base, base);
        n >>= 1;
    }
    return ans;
}
ll rev(ll num){
    return quick_pow(num, MOD-2);
}
int main(void){
    int n;
    cin >> n;
    vector<vector<int> > people(n + 1);
    vector<int> cnt(1e6 + 10);
    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        people[i].resize(k);
        for(int j=0; j<k; j++){
            cin >> people[i][j];
            cnt[ people[i][j] ] ++;
        }
    }
    ll ans = 0;
    for(int i=0; i<n; i++){
        //遍历每一个人
        for(auto item : people[i]){
            ans = add(ans, mul(mul(cnt[item], rev(n)), mul(rev(people[i].size()), rev(n))));
        }
    }
    cout << ans << endl;


    return 0;
}