#include<iostream>
using namespace std;
typedef long long ll;
int main(void){
    int n, num;
    cin >> n;
    ll A = 0, B = 0;
    for(int i=0; i<n; i++){
        cin >> num;
        int a = ( num + 1) >> 1, b = num - a;
        if(i & 1) A += a, B += b;
        else A += b, B += a;
    }
    cout << min(A, B) << endl;
    return 0;
}