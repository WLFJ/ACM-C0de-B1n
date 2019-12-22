#include<iostream>
#include<string>
using namespace std;
int main(void){
    int n, k;
    string s, t;
    cin >> n >> k >> s;
    t = s;
    for(int i=0; i<k; i++) t[i] = s[i];
    for(int i=k; i<n; i++) t[i] = t[i - k];

    if(t < s){
        for(int i=k-1; i>=0; i--){
            if(s[i] != '9'){
                for(int j=i; j<n; j += k)
                    t[j] ++;
                break;
            }else{
                for(int j=i; j<n; j+=k)
                    t[j] = '0';
            }
        }
    }
    cout << n << "\n" << t << endl;

    return 0;
}