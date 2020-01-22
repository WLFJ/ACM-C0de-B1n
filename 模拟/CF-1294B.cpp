#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using pii = pair<int, int>;
bool cmp(pii a, pii b){
    if(a.first != b.first){
        return a.first < b.first;
    }else if(a.second != b.second){
        return a.second < b.second;
    }
    return false;
}
int main(void){
    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        vector<pii> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i].first >> v[i].second;
        }
        sort(v.begin(), v.end(), cmp);
        int curX = 0, curY = 0;
        vector<char> path;
        bool isOK = true;
        for(pii nxt : v){
            if(curX > nxt.second || curY > nxt.first){
                isOK = false;
                break;
            }
            for(; curY < nxt.first; curY ++) path.push_back('R');
            for(; curX < nxt.second; curX ++) path.push_back('U');
        }
        if(isOK){
            cout << "YES" << endl;
            for(char c : path) cout << c;
        }
        else
            cout << "NO";
        cout << endl;
    }


    return 0;
}