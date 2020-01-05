#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using PII = pair<int, int>;
using LINT = long long;
int main(void){
    int n;
    cin >> n;
    LINT ans = 1LL * n * n;
    vector<PII> v;
    for(int i=0; i<n; i++){
        int len;
        cin >> len;
        vector<int> arr(len);
        for(int j=0; j<len; j++) cin >> arr[j];
        reverse(arr.begin(), arr.end());
        if(is_sorted(arr.begin(), arr.end())){
            v.emplace_back(arr[0], arr.back());//可以自动创建二元组！
        }
    }
    sort(v.begin(), v.end());
    for(auto a : v){
        ans -= v.end() - lower_bound(v.begin(), v.end(), PII(a.second, 0));
    }
    cout << ans << endl;
    return 0;
}