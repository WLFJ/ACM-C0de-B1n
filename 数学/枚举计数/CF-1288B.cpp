#include<iostream>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t --){
        long long a, b;
        cin >> a >> b;
        //现在我们要看b的范围
        long long maxNum = 9;
        long long cnt = 1;
        while(b >= maxNum){
            maxNum = maxNum * 10 + 9;
            cnt ++;
        }
        cout << a * 1LL * (cnt-1) << endl;
    }
    return 0;
}