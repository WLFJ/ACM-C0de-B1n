    #include<iostream>
    #include<algorithm>
    #include<vector>
    using namespace std;
    using PII = pair<int, int>;
    int main(void){
        /**
        现在我们要通过询问求解当前问的是第k大
        如果查询到比k小的 那么得到的结果是第K+1个数字
        如果查询到比k大的 那么得到的还是k
        所以我们要寻找出现次数为n-k的结果
        **/
        int n, k;
        cin >> n >> k;
        vector<int> mem(k + 2);
        for(int i=1; i<=k+1; i++){
            cout << "?";
            for(int j=1; j<=k+1; j++){
                if(i == j) continue;
                cout << " " << j;
            }
            cout << endl;
            int p, num;
            cin >> p >> mem[i];
        }
        sort(mem.begin(), mem.end());
        for(int i=1; i<=k; i++){
            if(mem[i] != mem[i + 1]){
                cout << "! " << k - i + 1 << endl;
                return 0; 
            }
        }
     
     
        return 0;
    }