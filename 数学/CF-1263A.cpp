#include<iostream>
#include<vector>
using namespace std;
int main(void){
    int q;
    cin >> q;
    while(q --){
        vector<int> color(3);
        for(int i=0; i<3; i++) cin >> color[i];
        sort(color.begin(), color.end());
        if(color[0] + color[1] <= color[2]) cout << color[0] + color[1] << endl;
        else cout << ( color[0] + color[1] + color[2] ) / 2 << endl;
    }

    return 0;
}