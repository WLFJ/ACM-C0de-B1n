#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(void){
    //读入两个串 交换第一个串的两个字母使得其严格小于后面的串
    //我们下手的地方肯定是大于的位置 之后再往下面比较
    /*
    只有大于的位置是必须需要作为处理点的
    后面的情况我们可以不看
    但是后面要存在一个比上面串小的字母在那么我们就贪心 遇到等于和小于的 对应上面找到最小的位置 如果遇到大于 则必须处理这里了
    现在我们知道通过交换两个字母生成最小是需要暴力交换的！
    */
   int t;
   cin >> t;
   while(t --){
       string a, b;
       cin >> a >> b;
       if(a < b){
           cout << a << endl;
       }else{
           string t = a;
           sort(t.begin(), t.end());
           bool isOK = false;
           for(int i=0; i<a.length(); i++){
               if(a[i] > t[i]){
                   int j;
                   for(int j=i+1; j<a.length(); j++){
                       swap(a[i], a[j]);
                       if(a < b){
                           cout << a << endl;
                           isOK = true;
                           break;
                       }
                       swap(a[i], a[j]);
                   }
                   if(isOK) break;
               }
           }
           if(isOK == false) cout << "---" << endl;
       }
   }

    return 0;
}