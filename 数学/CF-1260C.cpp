#include<iostream>
#include<algorithm>
using namespace std;
int main(void){
    int n;
    cin >> n;
    while(n --){
        int a, b, k;
        cin >> a >> b >> k;
        int t = __gcd(a, b);
        a /= t, b /= t;
        if(a * (k - 1) + 1 < b) cout << "REBEL" << endl;
        else cout << "OBEY" << endl;
    }


    return 0;
}