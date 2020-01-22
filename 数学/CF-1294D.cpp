#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
using namespace std;
int main(void){
    int q, x;
    cin >> q >> x;
    vector<int> v(x);
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < q; i ++){
        int num;
        cin >> num;
        v[num % x] ++;
        while(v[ans % x]) v[ans % x] -- , ans ++;
        cout << ans << endl;
    }
    return 0;
}