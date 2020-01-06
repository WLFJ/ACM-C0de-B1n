#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;//注意这个不是二倍的！
        vector<int> arr(n << 1);
        for(int i=0; i<n << 1; ++i) cin >> arr[i];

        //下面我们计算右边的前缀和
        map<int, int> mem;
        mem[0] = 0;
        int cur = 0;
        for(int i=n; i< n << 1; i++){
            if(arr[i] == 1) cur ++;
            else cur --;
            if(!mem.count(cur)) mem[cur] = i - n + 1;
        }
        int ans = n << 1;
        int diff = count(arr.begin(), arr.end(), 1) - count(arr.begin(), arr.end(), 2);
        cur = 0;
        for(int i=n-1; i>=0; --i){
            if(arr[i] == 1) cur ++;
            else cur --;
            if(mem.count(diff - cur)){
                ans = min(ans, n - i + mem[diff - cur]);
            }
        }
        if(mem.count(diff)){
            ans = min(ans, mem[diff]);
        }
        cout << ans << endl;
    }
    return 0;
}