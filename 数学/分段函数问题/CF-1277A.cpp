#include<iostream>
using namespace std;
/*
1～9
11 22 33 44 55 66 77 88 99
111 222 333 444 555 666 777
输入为1e9 那么现在我们要知道最高位置数字 确定是哪一个 之后计数
通过位数和开头的数字可以计算出来
(len - 1) * 9 + a
99999 135
*/
int main(void){
    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        int len = 0;
        int t = n;
        int beginNum = 0;
        while(t){
            len ++;if(t < 10) beginNum = t;
            t /= 10;
            
        }
        //下面我们比较一下大小以确定是不是我们要的
        int num = 1;
        for(int i=1; i<len; i++) num = num * 10 + 1;
        num *= beginNum;
        //cout << "@" << num << " " << beginNum << endl;
        while(n < num){
            //将其不断变小
            if(num % 10 != 1){
                num = num / (num % 10) * (num % 10 - 1);
                beginNum --;
            }else{
                num = num / 10 * 9;
                len --;
                beginNum = 9;
            }
        }
        //cout << "$" << len << " " << beginNum << endl;
        cout << (len - 1) * 9 + beginNum << endl;
    }

    return 0;
}