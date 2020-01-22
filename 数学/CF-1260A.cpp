#include<iostream>
using namespace std;
int main(void){
    int n;
    cin >> n;
    while(n --){
        int c, sum;
        cin >> c >> sum;
        int delta = sum % c;
        int add = sum / c;
        cout << (c - delta) * add * add + delta * (add + 1) * (add + 1) << endl;
    }


}