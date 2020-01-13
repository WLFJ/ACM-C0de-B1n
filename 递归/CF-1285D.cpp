#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
int solve(vector<ll> nums, int bits){
    if(nums.empty() || bits < 0) return 0;
    vector<ll> l, r;
    for(ll i : nums){
        if( (i >> bits) & 1 ) l.push_back(i);
        else r.push_back(i);
    }
    if(l.empty()) return solve(r, bits - 1);
    if(r.empty()) return solve(l, bits - 1);
    return min(solve(l, bits - 1), solve(r, bits - 1)) + ( 1 << bits );
}
int main(void){
    int n;
    cin >> n;
    vector<ll> nums(n);
    for(ll &i : nums) cin >> i;
    cout << solve(nums, 30) << endl;
    return 0;
}