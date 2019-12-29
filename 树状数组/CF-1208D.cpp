/*
当前串的前缀分析，因为后面的数字只能计算其前面小于的
并且当前序列中一定所有的数字都出现了，
那么我们知道最后一个数字的前缀和一定是其准确的前缀和
那么我们将其查询出来（直接查询前缀，对应的就是）
因为删除了一个数字，所以我们的前缀也要改变
因为这个数字可能在原来的数列中靠前的位置，
那么剩下数字的前缀和就需要动态修改，这样我们就要用到Fenwick Tree了
*/
#include<iostream>
#include<vector>
using namespace std;
 
template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;
 
  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
 
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
 
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};
 
int main(void){
    int n;
    cin >> n;
    vector<long long> s(n);
    fenwick<long long> fenw(n);
    for(int i=0; i<n; i++){
        fenw.modify(i, i+1);
        cin >> s[i];
    }
    vector<int> a(n);
    for(int i=n-1; i>=0; i--){
        int low = 0, high = n-1;
        while(low < high){
            int mid = (low + high) >> 1;
            if(fenw.get(mid) > s[i]) high = mid;
            else low = mid + 1;
        }
        a[i] = low + 1;
        fenw.modify(low, -low-1);
    }
 
    for(int i=0; i<n; i++){
        if(i) cout << " ";
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
