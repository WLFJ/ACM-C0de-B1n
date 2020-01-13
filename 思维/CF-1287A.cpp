#include<iostream>
#include<string>
using namespace std;
int main(void){
    /*
    现在要看经过多少分钟之后系统会变得稳定
    事实上我们只需要看一下最大长度的AxxxA子串就好了
    */
   int n;
   cin >> n;
   while( n --){
       int len;
       string s;
       cin >> len >> s;
       int lastS;
       for(lastS = 0; lastS < len; lastS ++) if(s[lastS] == 'A') break;
       int ans = 0, curS = lastS + 1;
       for(; curS < len; curS ++){
           if(s[curS] == 'A'){
               ans = max(ans, curS - lastS - 1);
               lastS = curS;
           }
       }
       ans = max(ans, curS - lastS - 1);
       cout << ans << endl;
   }

    return 0;
}