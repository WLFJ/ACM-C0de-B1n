#include<iostream>
using namespace std;
using ll = long long;
int main(void){
    int n;
    cin >> n;
    while(n --){
        ll num;
        cin >> num;
        if(num >= 15 && num < 21){
            cout << "YES" << endl;
            continue;
        }else if(num < 15){
            cout << "NO" << endl;
            continue;
        }else{
            //现在我们检查其倍数情况
            bool isOK = false;
            for(int delta = 15; delta <= 20; delta ++){
                ll newNum = num - delta;
                //cout << newNum << endl;
                if(newNum % 14 == 0){
                    isOK = true;
                    cout << "YES" << endl;
                    break;
                }
            }
            if(!isOK) cout << "NO" << endl;
        }
    }

    return 0;
}