#include<iostream>
#include<string>
#include<set>
using namespace std;
using ll = long long;
int main(void){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    set<char> mem;
    while(k --){
        char c;
        cin >> c;
        mem.insert(c);
    }
    ll ans = 0;
    ll cnt = 0;
    for(int i=0; i<s.length(); i++){
        if(mem.count(s[i])){
            cnt ++;
        }else{
            ans += cnt * (cnt + 1) / 2;
            cnt = 0;
        }
    }
    ans += cnt * (cnt + 1) / 2;

    cout << ans << endl;
    


    return 0;
}