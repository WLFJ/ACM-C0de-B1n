#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        vector<int> mem;
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                mem.push_back(i);
                mem.push_back(n / i);
            }
        }
        unique(mem.begin(), mem.end());
        int sz = mem.size();
        bool isOK = false;
        for(int a = 1; a < sz; a ++){
            for(int b = 1; b < sz; b ++){
                if(a == b) continue;
                for(int c = 1; c < sz; c ++){
                    if(c == a||c == b) continue;
                    if(mem[a] * mem[b] * mem[c] == n){
                        isOK = true;
                        cout << "YES" << endl;
                        cout << mem[a] << " " << mem[b] << " " << mem[c] << endl;
                        goto OKK;
                    }
                }
            }
        }
        OKK:;
        if(isOK == false) cout << "NO" << endl;
    }




    return 0;
}