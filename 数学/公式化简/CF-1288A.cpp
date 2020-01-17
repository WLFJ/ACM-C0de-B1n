#include<iostream>
using namespace std;
using ll = long long;
int main(void){
    int T;
    cin >> T;
    while(T--){
        ll n, d;
        cin >> n >> d;
        ll mid = (4 * d) / (n + 1);
        if((4 * d) % (n + 1)) mid ++;
        if(n - 1 + mid <= 2 * n){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }


    return 0;
}