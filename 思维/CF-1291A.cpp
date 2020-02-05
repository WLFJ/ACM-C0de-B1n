#include<iostream>
#include<string>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t --){
        int len;
        cin >> len;
        string num;
        cin >> num;
        int cnt = 0;
        string ans = "";
        for(int i = 0; i < len && cnt < 2; i ++){
            if((num[i] - '0') % 2 == 1){
                ans += num[i];
                cnt ++;
            }
        }
        if(cnt == 2) cout << ans << endl;
        else cout << -1 << endl;
    }


    return 0;
}