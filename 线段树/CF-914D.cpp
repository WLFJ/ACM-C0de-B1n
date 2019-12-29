#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e6 +5;
 
struct node{
    int l, r, w;
}tree[MAXN << 2];
 
unsigned long long cnt = 0;
void build(int l, int r, int k){
    tree[k].l = l, tree[k].r = r;
    if(l == r){
        scanf("%d", &tree[k].w);
        return;
    }
    int mid = (l + r) >> 1, nextK = k << 1;
    build(l, mid, nextK);
    build(mid+1, r, nextK | 1);
    tree[k].w = __gcd(tree[nextK].w, tree[nextK|1].w);
}
 
void query(int l, int r, int x, int k){
    if(tree[k].l == tree[k].r){//能到这里说明一定不满足条件
        cnt ++;
        return;
    }
    if(tree[k].l >= l && tree[k].r <= r){
        //完全在区间里面的情况
        //我们可以统计有x的数量，如果上面满足了 那么下面就不用看了
        //如果不满足则我们要向其子树看一下
        if(tree[k].w % x == 0) return;
        if(tree[k<<1].w%x && tree[k<<1|1].w%x){
            cnt += 2;
            return;
        }
    }
    int mid = (tree[k].l + tree[k].r) >> 1;
    //看情况，如果当前已经是0那就不用搜了
    if(l <= mid && tree[k<<1].w%x) query(l, r, x, k << 1);
    if(r > mid && tree[k<<1 | 1].w%x) query(l, r, x, k << 1 | 1);
}
 
void change(int p, int m, int k){//根据指导搜索，我们可以直接在传下标判断！
    if(tree[k].l == tree[k].r){
        tree[k].w = m;
        return;
    }
    int mid = (tree[k].l + tree[k].r) >> 1;
    if(p <= mid) change(p, m, k << 1);
    else change(p, m, k << 1 | 1);
    tree[k].w = __gcd(tree[k<<1].w, tree[k<<1|1].w);
}
int main(void){
    int n;
    scanf("%d", &n);
    build(1, n, 1);
    int q;
    scanf("%d", &q);
    while(q--){
        int id;
        scanf("%d", &id);
        switch(id){
            case 1:
                int l, r, x;
                scanf("%d%d%d", &l, &r, &x);
                cnt = 0;
                query(l, r, x, 1);
                if(cnt <= 1) puts("YES");
                else puts("NO");
                break;
            case 2:
                int i, y;
                scanf("%d%d", &i, &y);
                change(i, y, 1);
                break;
        }
    }
    return 0;
}
