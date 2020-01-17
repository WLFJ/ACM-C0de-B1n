#include<iostream>
#include<vector>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int ans = 1;
    vector<int> left(n, 1);
    vector<int> right(n, 1);
    for(int i=n-2; i>=0; i--){
        if(v[i + 1] > v[i]) right[i] = right[i+1] + 1;
        ans = max(ans, right[i]);
    }
    for(int i=1; i<n; i++){
        if(v[i] > v[i-1]) left[i] = left[i-1] + 1;
        ans = max(ans, left[i]);
    }
    for(int i=0; i<n-2; i++){
        if(v[i] < v[i+2]) ans = max(ans, left[i] + right[i + 2]);
    }

    cout << ans << endl;




    return 0;
}