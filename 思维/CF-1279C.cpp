#include<iostream>
#define int long long
using namespace std;
const int MAXN = 1e5 + 10;
int a[MAXN], b[MAXN];
int pos[MAXN];
signed main(void){
    int t;
    cin >> t;
    while(t --){
        int n, m;
        cin >> n >> m;
        for(int i=0; i<n; i++){
            cin >> a[i];
            a[i] --;
            pos[ a[i] ] = i;
        }
        int maxX = 0;
        int ans = 0;
        for(int i=0; i<m; i++){
            cin >> b[i];
            b[i] --;
            int x = pos[ b[i] ];
            if(x > maxX){
                maxX = x;
                ans += (x - i) << 1 | 1;
            }else ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}