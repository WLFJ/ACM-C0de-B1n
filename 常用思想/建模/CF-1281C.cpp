#include<iostream>
#include<string>
#include<vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
int main(void){
    /*
    本题的关键是将题目中的量使用合理的式子表示出来，之后肯定有需要转换的地方，我们努力进行等价转换，之后大力枚举。
    */
    int t;
    cin >> t;
    while(t --){
        int x;
        string s;
        cin >> x >> s;
        ll len = s.length();
        vector<char> v(s.begin(), s.end());
        for(int i=1; i<=x; i++){
            int times = v[i - 1] - '0';//得到拷贝次数
            if(v.size() < x){
                vector<char> sub(v.begin() + i, v.end());
                for(int j=1; j<=times - 1; j++){
                    v.insert(v.end(), sub.begin(), sub.end());
                }    
            }
            len = (len + (len - i) * (times - 1)) % MOD;
        }
        cout << (len + MOD) % MOD << endl;
    }
    return 0;
}