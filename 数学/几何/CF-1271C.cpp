#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int nx[] = {-1, 0, 1, 0};
int ny[] = {0, -1, 0, 1};
int main(void){
    /*
    事实上非常简单！
    注意这里我们学习到：如何判断一个点在哪个方向上？（长方形里面 感受一下～）我们只需要在必经之路上取出一个点 看一下他们的距离是否等于直接距离
    */
   int N, s_x, s_y;
   cin >> N >> s_x >> s_y;
   vector<int> cnt(4);
   while(N --){
       int x, y;
       cin >> x >> y;
       int distance = abs(x - s_x) + abs(y - s_y);
       for(int i=0; i<4; i++){
           if( 1 + abs(x - s_x - nx[i]) + abs(y - s_y - ny[i]) == distance ){
               cnt[i] ++;
           }
       }
   }
   int maxTag = 0;
   for(int i=0; i < 4; i++){
       if(cnt[maxTag] < cnt[i]) maxTag = i;
   }
   cout << cnt[maxTag] << endl;
   cout << s_x + nx[maxTag] << " " << s_y + ny[maxTag] << endl;
    return 0;
}