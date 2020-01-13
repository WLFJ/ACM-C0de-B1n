#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}
int main(void){
    ll num;
    cin >> num;
    ll ans;
    for(ll i; i * i <= num; i ++){
        if(num % i == 0 && lcm(i, num / i) == num){
            ans = i;
        }
    }
    cout << ans << " " << num/ans << endl;
    return 0;
}