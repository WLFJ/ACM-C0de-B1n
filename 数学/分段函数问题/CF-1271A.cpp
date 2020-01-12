#include<iostream>
using namespace std;
int main(void){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    //a + d --> e, b + c + d --> f
    int ans = 0;
    //我们肯定要计算价值最大的 之后是价值少的再计算进去
    int cntA = min(a, d), cntB = min(b, min(c, d));
    if(e >= f){
        ans = cntA * e;
        d -= cntA;
        if(d > 0)
            ans += f * min(b, min(c, d));
    }else{
        ans = cntB * f;
        d -= cntB;
        if(d > 0)
            ans += e * min(a, d);
    }

    cout << ans << endl;
    return 0;
}