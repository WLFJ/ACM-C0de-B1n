#include<iostream>
#include<string>
using namespace std;
int main(void){
    int n;
    cin >> n;
    string s;
    cin >> s;
    //相当于问用a个-1和b个+1可以凑出多少个数字
    //2 * -1
    //2 * 1
    int a = 0, b = 0;
    for(int i=0; i<n; i ++){
        if(s[i] == 'L') a --;
        else b ++;
    }
    cout << b - a + 1 << endl;
    return 0;
}