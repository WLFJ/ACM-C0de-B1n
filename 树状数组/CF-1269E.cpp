#include<iostream>
#define int long long
using namespace std;
const int MAXN = 200000 + 10;
int BIT1[MAXN], BIT2[MAXN];
int N;
void update(int p, int num, int *BIT){
    //修改是上升操作
    for(; p <= N; p += p & -p){
        BIT[p] += num;
    }
}
int query(int p, int *BIT){
    int sum = 0;
    for(; p>0; p-=p & -p){
        sum += BIT[p];
    }
    return sum;
}
int arr_num[MAXN], arr_pos[MAXN];
signed main(void){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr_num[i];
        arr_pos[ arr_num[i] ] = i;
    }
    int ans = 0;
    for(int i=1; i<=N; i++){
        ans += i - query(arr_pos[i], BIT1) - 1;
        update(arr_pos[i], 1, BIT1);
        update(arr_pos[i], arr_pos[i], BIT2);
        int lb = 1, ub = N;
        while(ub > lb){
            int mid = (lb + ub + 1) >> 1;
            if(query(mid - 1, BIT1) > i / 2){
                ub = mid - 1;
            }else{
                lb = mid;
            }
        }
        //ans is *ub*
        int upper = query(N, BIT1) - query(ub, BIT1);//[ub+1, N]
        int add1 = query(N, BIT2) - query(ub, BIT2) - ub * upper - (1 + upper) * upper / 2;
        int lower = query(ub-1, BIT1);//[1, ub-1]
        int add2 = ub * lower - query(ub-1, BIT2) - (1 + lower) * lower / 2;
        //cout << upper << " " << lower << " " << add1 << " " << add2 << endl;
        cout << ans + add1 + add2 << " ";
    }
    cout << endl;
    return 0;
}