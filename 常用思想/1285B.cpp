#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
int main(void){
    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        vector<ll> preSum(n + 1);
        ll Min = 1e15, Max = -1e15;
        for(int i=1; i<=n; i++){
            cin >> preSum[i];
            preSum[i] += preSum[i - 1];
        }
        //注意我们只能要最大值前面的最小值
        int maxPos = 0;
        for(int i=0; i<=n; i++){
            if(preSum[i] > Max){
                maxPos = i;
                Max = preSum[i];
            }
        }
        int minPos = 0;
        for(int i=0; i<=maxPos; i++){
            if(preSum[i] < Min){
                Min = preSum[i];
                minPos = i;
            }
        }
        ll segSum = Max - Min;
        cout << preSum[n] << " " << segSum << endl;
        if(segSum < preSum[n] || (preSum[n] == segSum && minPos == 0 && maxPos == n)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }


    return 0;
}