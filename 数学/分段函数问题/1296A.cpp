#include<iostream>
#include<vector>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        int ji = 0, ou = 0;
        int num;
        for(int i = 0; i < n; i ++){
            cin >> num;
            if(num & 1) ji ++;
            else ou ++;
        }
        if(ji & 1){
            cout << "YES" << endl;
        }else if(ji){
            if(ou == 0) cout << "NO" << endl;
            else cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }


    return 0;
}