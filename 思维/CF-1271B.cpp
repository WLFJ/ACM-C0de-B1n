#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(void){
    /*
    事实上这道题目给人一种子问题的感觉
    这种东西也没有办法处理啊
    首先我们要知道应该处理的是B还是W！
    我们知道奇数个是没有办法转换的 所以我们不能随便选择
    首先统计一下哪一个的数量为偶数-我们只操作数量为偶数的
    知道数量关系之后我们似乎可以直接扫描过去啦！
    */
   int len;
   cin >> len;
    string s;
    cin >> s;
    int cnt_B = 0, cnt_W = 0;
    for(int i=0; i<len; i++){
        if(s[i] == 'B') cnt_B ++;
        else cnt_W ++;
    }
    if(cnt_B == 0 || cnt_W == 0){
        cout << 0 << endl;
        return 0;
    }
    char checker = cnt_W & 1 ? 'W' : 'B';
    cout << checker << endl;
    if((cnt_W & 1) && (cnt_B & 1)) cout << -1 << endl;
    else{
        vector<int> ans;
        for(int i=0; i<len-1; i++){
            if(s[i] != checker){
                ans.push_back(i + 1);
                s[i] = checker;
                s[i + 1] = s[i + 1] == 'B' ? 'W' : 'B';
            }
        }
        cout << ans.size() << endl;
        for(int i : ans){
            cout << i << " ";
        }
        cout << endl;
    }



    return 0;
}