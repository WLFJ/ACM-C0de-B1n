#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int MAXN = 105;
int dp[MAXN][MAXN][MAXN][2];
int main(void){
    int n;
    cin >> n;
    int even = n >> 1, odd = n - even;
    vector<int> v(n + 1);
    for(int i=1; i<=n; i ++){
        cin >> v[i];
        if(v[i]){
            even -= !(v[i] & 1);
            odd -= (v[i] & 1);
        }
    }
    //还需要计算前面零的个数
    vector<int> cntZero(n + 1);
    for(int i=1; i<=n; i++){
        if(v[i]) cntZero[i] = cntZero[i-1];
        else cntZero[i] = cntZero[i-1] + 1;
    }

    //cout << even << " " << odd << endl;
    memset(dp, 0x3f, sizeof dp);
    dp[0][1][1][0] = dp[0][1][1][1] = 0;
    for(int p=1; p<=n; p++){
        for(int i=1; i<=even + 1; i++){
            for(int j=1; j <= odd + 1; j++){
                if(i + j > cntZero[p] + 2) break;
                if(v[p]){//如果当前是数字
                    dp[p][i][j][v[p] & 1] = min(dp[p-1][i][j][v[p] & 1], dp[p-1][i][j][!(v[p] & 1)] + 1);
                }else{//如果当前是空则要填写数字
                    dp[p][i][j][0] = min(dp[p-1][i-1][j][0], dp[p-1][i-1][j][1] + 1);
                    dp[p][i][j][1] = min(dp[p-1][i][j-1][1], dp[p-1][i][j-1][0] + 1);
                }
            }
        }
    }

    cout << min(dp[n][even+1][odd+1][0], dp[n][even+1][odd+1][1]) << endl;


    return 0;
}