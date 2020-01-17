#include<iostream>
#include<cmath>
using namespace std;
using ll = long long;
int cal[] = {-1, 0, 1};
int main(void){
    int q;
    cin >> q;
    while(q --){
        ll minNum = 1e9 + 1, maxNum = -1;
        for(int i=0; i<3; i++){
            ll num;
            cin >> num;
            minNum = min(minNum, num);
            maxNum = max(maxNum, num);
        }
        cout << (((maxNum - minNum - 2) >= 0 ? maxNum - minNum - 2 : 0) << 1) << endl;
    }


    return 0;
}