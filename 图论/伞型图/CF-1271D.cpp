#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 5010;
int a[MAXN], b[MAXN], c[MAXN];
int parent[MAXN];
vector<int> adjacent[MAXN];
int pnum[MAXN][MAXN];

int mem[MAXN][MAXN];

bool cmp(int a, int b){
    return c[a] > c[b];
}

int n;

int dp(int id, int k){
    if(a[id] > k) return -1000000000;
    if(id > n) return 0;
    int &ans = mem[id][k];
    if(ans != -1) return ans;
    k += b[id];
    ans = dp(id + 1, k);
    for(int i=0; i < (int)adjacent[id].size(); i++){
        ans = max(ans, dp(id + 1, k - i - 1) + pnum[id][i]);
    }
    return ans;
}

int main(void){
    memset(mem, -1, sizeof mem);
    int m, k;
    cin >> n >> m >> k;//读入城堡 通道 开始时候兵力
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    //下面读入通道数量
    for(int i=0; i<n; i++) parent[i] = i;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        --a, --b;
        parent[b] = max(parent[b], a);
    }
    //下面处理每一个节点的邻接节点情况
    for(int i=0; i<n; i++){
        adjacent[ parent[i] ].push_back(i);
    }
    //下面计算每一个节点后面的前缀和
    for(int i=0; i<n; i++){
        sort(adjacent[i].begin(), adjacent[i].end(), cmp);
        for(int j=0; j<(int)adjacent[i].size(); j++){
            pnum[i][j] = (j ? pnum[i][j-1] : 0) + c[ adjacent[i][j] ];
        }
    }
    //下面就要求解啦！
    int ans = dp(0, k);
    cout << (ans < 0 ? -1 : ans) << endl;
    return 0;
}