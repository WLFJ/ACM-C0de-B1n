#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
    int q;
    cin >> q;
    while(q --){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin >> v[i];
        int pos = 0;
        while(pos < n){
            int nxt = min_element(v.begin() + pos, v.end()) - v.begin();
            int n = v[nxt];
            v.erase(v.begin() + nxt);
            v.insert(v.begin() + pos, n);
            if(pos == nxt) pos = nxt + 1;
            else pos = nxt;
        }
        for(int a : v) cout << a << " ";
        cout << endl;
    }


    return 0;
}