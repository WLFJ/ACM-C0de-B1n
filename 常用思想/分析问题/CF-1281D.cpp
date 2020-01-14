#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 65;
char maze[MAXN][MAXN];
int r, c;
/*
这种暴力非把自己搞死 让我们枚举一下所有的情况
答案为0
所有的都是A
答案为1
边上有一行或者一列是A
答案为2
角上是A 或者中间有一行或者一列是A
答案是3
边上除了角上有A
答案是4
除了上面的情况 只要中间有A就是了
*/
int solve_NOTLE(){

    int sum = 0;
    vector<int> col_sum(c);
    vector<int> row_sum(r);
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            sum += maze[i][j];
            col_sum[j-1] += maze[i][j];
            row_sum[i-1] += maze[i][j];
        }
    }

    //cout << col_sum[0] << "@" << endl;

    if(sum == r * c) return 0;
    else if(sum == 0) return -1;
    else if(col_sum[0] == r || row_sum[0] == c || col_sum.back() == r || row_sum.back() == c) return 1;
    else if(maze[1][1] || maze[1][c] || maze[r][1] || maze[r][c]) return 2;
    else if(*(max_element(col_sum.begin(), col_sum.end())) == r || *(max_element(row_sum.begin(), row_sum.end())) == c) return 2;
    else if(col_sum[0] || col_sum.back() || row_sum[0] || row_sum.back()) return 3;
    else return 4;

}
int solve(int step, int begin){
    int ans = 0x3f3f3f3f;
    for(int i=begin; i<=r; i+=step){
        //首先处理当前行的边上是否有1！
        int times = !maze[i][1] + !maze[i][c];
        //如果发现有的话 则游戏结束
        if(times == 2){
            //我们要寻找中间有没有
            for(int j=1; j<=c; j++){
                if(maze[i][j]){
                    times ++;
                    break;
                }
            }
            if(times == 2) times = 0x3f3f3f3f;
        }else{
            //现在我们要看
            int sum = 0;
            for(int j=1; j<=c; j++) sum += maze[i][j];
            if(sum == c) times = 1;
            else times = 2;
        }
        ans = min(ans, times);
    }
    return ans;
}
int solve1(int step, int begin){
    int ans = 0x3f3f3f3f;
    for(int i=begin; i<=c; i+=step){
        //首先处理当前行的边上是否有1！
        int times = !maze[1][i] + !maze[r][i];
        //如果发现有的话 则游戏结束
        if(times == 2){
            //我们要寻找中间有没有
            for(int j=1; j<=r; j++){
                if(maze[j][i]){
                    times ++;
                    break;
                }
            }
            if(times == 2) times = 0x3f3f3f3f;
            //cout << i << "!" << endl;
        }else{
            int sum = 0;
            for(int j=1; j<=r; j++) sum += maze[j][i];
            if(sum == r) times = 1;
            else times = 2;
        }
        //cout << "@" << times << endl;
        ans = min(ans, times);
    }
    return ans;
}
int main(void){
    int t;
    cin >> t;
    while(t --){
        cin >> r >> c;
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                cin >> maze[i][j];
                maze[i][j] = maze[i][j] == 'A';
            }
        }
        // //现在数据读完了 现在我们找1
        // //看一下行的情况（第一行和最后一行）
        // int ans = 0x3f3f3f3f;
        // ans = min(ans, solve(r - 1, 1));
        // //下面我们横着看中间
        // ans = min(ans, solve(1, 2) + 1);//计算没问题！但是竖着计算就出现问题了！
        // //下面我们看竖着的
        // ans = min(ans, solve1(c - 1, 1));
        // ans = min(ans, solve1(1, 2) + 1);

        // if(ans == 0x3f3f3f3f){
        //     cout << "MORTAL" << endl;
        // }else{
        //     cout << ans << endl;
        // }
        int ans = solve_NOTLE();
        if(~ans){
            cout << ans << endl;
        }else{
            cout << "MORTAL" << endl;
        }
    }
    return 0;
}