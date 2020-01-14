#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main(void){
    //问操作次数 事实上我们要找出是因数的数字 因为到后期可以一起处理
    //现在我们要消去a的k倍 应该怎么做呢 在当前列表中直接比较嘛
    //我们需要保存基数 最后计算其得数
    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        vector<int> v;
        while(n --){
            int num;
            cin >> num;
            if((num & 1) == 0) v.push_back(num);
        }
        int ans = 0;
        unique(v.begin(), v.end());
        sort(v.begin(), v.end());
        set<int> mem;
        vector<int> process;
        for(int i = v.size() - 1; i >= 0; i --){
            int num = v[i];
            int cnt = 0;
            while(!(num & 1)) num >>= 1, cnt ++;
            if(!mem.count(num)){
                ans += cnt;
                mem.insert(num);
                //cout << num << endl;
            }
        }
        cout << ans << endl;
    }


    return 0;
}