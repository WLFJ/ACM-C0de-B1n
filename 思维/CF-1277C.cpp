#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(void){
    /*
    现在的关键是删除之后后面的东西可能会是相同的！所以最少的个数还是有难度的

    */

    int t;
    cin >> t;
    while(t --){
        string s;
        cin >> s;
        vector<int> ans;
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'o' && i - 2 >= 0){
                if(s[i-2] == 't' && s[i-1] == 'w'){
                    //我们要看后面的情况
                    if(i + 1 < s.length() && s[i+1] == 'o'){
                        ans.push_back(i - 1);
                    }else{
                        s[i] = 'X';
                        ans.push_back(i);
                    }
                }
            }
            if(s[i] == 'o' && i + 2 < s.length()){
                if(s[i+1] == 'n' && s[i+2] == 'e'){
                    if(i - 1 >= 0 && s[i-1] == 'o'){
                        ans.push_back(i + 1);
                    }else{
                        s[i] = 'X';
                        ans.push_back(i);
                    }
                }
            }   
        }
        cout << ans.size() << endl;
        for(int i : ans) cout << i + 1 << " ";
        cout << endl;
    }
    return 0;
}