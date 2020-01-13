#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int dic[] = {' ', 'S', 'E', ' ', 'T'};
int getID(char c){
    if(c == 'S') return 1;
    else if(c == 'E') return 2;
    else if(c == 'T') return 4;
    else return -1;
}
int main(void){
    /*
    数据量很小 暴力应该可以
    说是选择三个 事实上选择两个之后看第三个是否存在就可以了
    但是问题是不同的特性中间也可能有选择，如果长度不同的话又该怎么办
    注意！这里说的是长度为K，要求就是各不相同！
    */
   int n, k;
   cin >> n >> k;
   vector<string> mem;
   set<string> ss;
   set<pair<int, int> > sii;
   for(int i=0; i<n; i++){
       string s;
        cin >> s;
        mem.push_back(s);
        ss.insert(s);
   }
   int ans = 0;
   for(int i=0; i<n; i++){//1500
       for(int j=0; j<n; j++){//1500
           if(i == j) continue;
           //首先保证所选的这两个是不同的，然后生成一个字符串，在集合中查找一下
           string newS = "";
           int counter = 0;
           for(int p=0; p<k; p++){//30
               //在这里计数一下不同位置 同时生成一个新的串
               if(mem[i][p] != mem[j][p]){
                   newS += dic[7 - getID(mem[i][p]) - getID(mem[j][p])];
               }else{
                   newS += mem[i][p];
                   counter ++;
               }
           }
           //if(counter & 1) continue;
           //cout << i << ":" << j << " " << mem[i] << " " << mem[j] << " " << newS << endl;
           if(ss.count(newS)){
               //cout << i << " " << j << endl;
               ans ++;
           }
       }
   }
   cout << ans / 6 << endl;


    return 0;
}