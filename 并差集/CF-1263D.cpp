#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;
int alhabet_parent['z' + 1];
int findParent(char c){
    if(c == alhabet_parent[c]) return c;
    else return alhabet_parent[c] = findParent(alhabet_parent[c]);
}
void Union(char a, char b){
    a = findParent(a), b = findParent(b);
    alhabet_parent[b] = a;
}
int main(void){
    for(char c = 'a'; c <= 'z'; c ++) alhabet_parent[c] = c;
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
        char root = arr[i][0];
        for(char c : arr[i]){
            Union(root, c);
        }
    }
    set<int> cnt;
    for(string s : arr){
        cnt.insert(findParent(s[0]));
    }
    cout << cnt.size() << endl;
    return 0;
}