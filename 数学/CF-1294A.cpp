#include<iostream>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while( t -- ){
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        int total = a + b + c + n;
        int avg = total / 3;
        if(total % 3 == 0 && avg - a >= 0 && avg - b >= 0 && avg - c >= 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }


    return 0;
}