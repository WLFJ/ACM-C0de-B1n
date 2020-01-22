#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
using namespace std;
int main(void){
    //现在的问题是要修改最少的数字使得其是不同的
    //因为输入最多10张 所以通过更改最后一位数字肯定是有解的

    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        int num;
        set<int> mem, ans;
        vector<int> out;
        //要按照原来的顺序输出！我太难了
        //注意我们在生成的时候注意检查谁重复最多再生成！
        while(n --){
            cin >> num;
            if(mem.count(num)){
                int lastDigit = num % 10;
                num /= 10;
                while(mem.count(num * 10 + (lastDigit + 10) % 10)) lastDigit = (lastDigit + 1) % 10;
                num = num * 10 + lastDigit;
                ans.insert(num);
            }
            mem.insert(num);
            out.push_back(num);
        }
        cout << ans.size() << endl;
        for(int num : out){
            printf("%04d\n", num);
        }
        
    
    }


    return 0;
}