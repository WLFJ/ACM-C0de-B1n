#include<iostream>
#include<string>
using namespace std;
int main(void){
    int q;
    cin >> q;
    while(q --){
        string s;
        cin >> s;
        int L = 0, R = 0, U = 0, D = 0;
        for(char c : s){
            if(c == 'L') L ++;
            else if(c == 'R') R++;
            else if(c == 'U') U ++;
            else D ++;
        }
        //检查是否有解？
        int check = (bool)L + ((bool)R << 1) + ((bool)U << 2) + ((bool)D << 3); 
        if(!(check == 3 || check == 12 || check == 15 || check == 14 || check == 13 || check == 11 || check == 7)){
            cout << 0 << endl;
            continue;
        }
        if(U == 0 || D == 0){
            cout << "2\nLR" << endl;
            continue;
        }
        if(L == 0 || R == 0){
            cout << "2\nUD" << endl;
            continue;
        }
        int ansLen = (min(L, R) + min(U, D)) << 1;
        cout << ansLen << endl;
        //下面是构造时间
        for(int i=0; i<min(L, R); i++){
            cout << "L";
        }
        for(int i=0; i<min(U, D); i++){
            cout << "U";
        }
        for(int i=0; i<min(L, R); i++){
            cout << "R";
        }
        for(int i=0; i<min(U, D); i++){
            cout << "D";
        }
        cout << endl;
    }


    return 0;
}