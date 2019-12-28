#include<iostream>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t --){
        int r, g, b;
        cin >> r >> g >> b;
        //能不能使用这些构造一个没有分割的串呢？
        if((r + g + 1 < b || r + b + 1 < g || g + b + 1 < r) && r + g + b != 1){
            cout << "No" << endl;
        }else
            cout << "Yes" << endl;
    }
    return 0;
}