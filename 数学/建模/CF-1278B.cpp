#include<iostream>
#include<cmath>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t --){
        int a, b;
        cin >> a >> b;
        int d = abs(a - b);
        if(d == 0){
            cout << 0 << endl;
            continue;
        }
        long long solution;
        for(solution = 1; 1; solution ++){
            long long delta = solution * 1LL * (solution + 1) >> 1;
            if( delta >= d && (delta % 2 == d % 2)) break;
        }
        cout << solution << endl;
    }


    return 0;
}