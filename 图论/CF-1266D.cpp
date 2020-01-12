#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(void){
    //是时候学习一下如何使用STL了！同时我们还应该学习一下怎样使用JavaA题啊！
    int n, m;
    cin >> n >> m;
    vector<ll> money(n);
    for(int i=0; i<m; i++){
        int a, b, u;
        cin >> a >> b >> u;
        money[--a] -= u;
        money[--b] += u;
    }

    vector<pair<int, long long> > mem;

    for(int i=0; i<n; i++){
        if(money[i] < 0){
            mem.emplace_back(i, -money[i]);
        }
    }

    vector< tuple<int, int, long long> > ans;
    
    for(int i=0; i<n; i++){
        while(money[i] > 0){
            long long cost = min(money[i], mem.back().second);
            money[i] -= cost;
            mem.back().second -= cost;
            ans.emplace_back(i, mem.back().first, cost);//这里出现问题了！
            if(mem.back().second == 0) mem.pop_back();
        }
    }

    cout << ans.size() << endl;

    for(auto& a : ans){
        cout << get<1>(a) + 1 << " " <<  get<0>(a) + 1 << " " << get<2>(a) << endl;
    }

    return 0;
}