#include<iostream>
using namespace std;
int main(void){
    int r, c;
    cin >> r >> c;
    if(r == c && r == 1){
        cout << 0 << endl;
        return 0;
    }
    if(r == 1){
        for(int i=1; i<=c; i++){
            cout << i + 1 << " ";
        }
        cout << endl;
        return 0;
    }
    if(c == 1){
        for(int i=1; i<=r; i++){
            cout << i + 1 << endl;
        }
        return 0;
    }
    for(int i=1; i<=r; i++){
        for(int j = 1; j <= c; j++){
            cout << i * (j + r) << " ";//注意理清思路
        }
        cout << endl;
    }
    return 0;
}