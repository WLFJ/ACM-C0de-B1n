#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main(void){
    int n;
    cin >> n;
    while(n --){
        int s;
        cin >> s;
        int t = (int)sqrt(s);
        vector<int> ans;
        for(int i=0; i<=t; i++){
            ans.push_back(i);
            if(i) ans.push_back(s / i);
        }
        sort(ans.begin(), ans.end());
        ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
        cout << ans.size() << endl;
        for(int num : ans) cout << num << " ";
        cout << endl;
    }


    return 0;
}