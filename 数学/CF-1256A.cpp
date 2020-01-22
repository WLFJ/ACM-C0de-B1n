#include<iostream>
using namespace std;
int main(void){
    int q;
    cin >> q;
    while(q --){
        int a, b, n, s;
        cin >> a >> b >> n >> s;
        //a个n b个1 能够凑出S？
        if(s - n * min(s / n, a) <= b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}