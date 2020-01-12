#include<iostream>
#include<string>
using namespace std;
int main(void){
    //中国剩余定理
   int n;
   cin >> n;
   while(n --){
       string s;
       cin >> s;
       //cout << s << endl;
       int sum = 0;
       int cntEven = 0;
       bool haveZero = false;
       for(char i : s){
           sum += i - '0';
           cntEven += !((i - '0') & 1);
           if(i == '0') haveZero = true;
       }
       if((cntEven >= 2 && (sum % 3 == 0)) && haveZero) cout << "red" << endl;
       else cout << "cyan" << endl;
   }
    return 0;
}