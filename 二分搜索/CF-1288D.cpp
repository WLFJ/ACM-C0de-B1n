#include<iostream>
#include<vector>
using namespace std;
int n, m;
int a, b;
bool check(vector<vector<int> > matrix, int num){
//注意明确自己的思路！我们在得到一个数字之后，要看其能否满足题意！
    vector<int> mask(1 << m, -1);
    for(int i=0; i<n; i++){
        int cur = 0;
        for(int j=0; j<m; j++){
            if(matrix[i][j] >= num)
                cur ^= (1 << j);
        }
        mask[cur] = i;
    }
    if(mask[(1 << m) - 1] != -1){
        a = b = mask[(1 << m) - 1];
        return true;
    }
    for(int i=0; i<(1 << m); i++){
        for(int j=0; j<(1 << m); j++){
            if(mask[i] != -1 && mask[j] != -1 && (i | j) == (1 << m) - 1){
                return a = mask[i], b = mask[j], true;
            }
        }
    }
    return false;
}
int main(void){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vector<vector<int> > matrix(n, vector<int>(m));
    int minNum = 1e9 + 7, maxNum = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> matrix[i][j];
            maxNum = max(maxNum, matrix[i][j]);
            minNum = min(minNum, matrix[i][j]);
        }
    }
    //现在我们要找的是最大值也就是要往右边去 的 那么这个应该怎样写呢？
    minNum --, maxNum ++;//注意这里的区间要写稍微大一点！不然会出现取不到值的情况！
    while(maxNum - minNum > 1){
        int mid = (minNum + maxNum + 1) >> 1;
        if(check(matrix, mid)){
            minNum = mid;
        }else{
            maxNum = mid - 1;
        }
    }
    cout << a + 1 << " " << b + 1 << endl;
    return 0;
}