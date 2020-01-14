#include<iostream>
#include<string>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t --){
        string s;
        cin >> s;
        string sub_a = s.substr(s.length() - 2, 2), sub_b = s.substr(s.length() - 4, 4);
        if(sub_a == "po"){
            cout << "FILIPINO" << endl;
        }else if(sub_b == "desu" || sub_b == "masu"){
            cout << "JAPANESE" << endl;
        }else{
            cout << "KOREAN" << endl;
        }
    }


    return 0;
}