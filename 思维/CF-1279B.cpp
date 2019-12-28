    #include<iostream>
    #define int long long
    using namespace std;
    const int MAXN = 1e5 + 10;
    int arr[MAXN];
    signed main(void){
        int t;
        cin >> t;
        while(t --){
            int n, s;
            cin >> n >> s;
            for(int i=1; i<=n; i++) cin >> arr[i];
            /**
             * 现在问 删除其中哪一个数字 从开头开始的最大子列个数最多？
             * 也就是 删除一个数字 能从后面最大拿出多少个数字来？
             * 自然要删除当前子列中最大的数字 然后计算后面加入的数字个数啦！
             *
            **/
            int cnt = 0;
            int i = 1;
            int maxNum = 0, maxP = 0;
            for(; i<=n && cnt <= s; i++){
                cnt += arr[i];
                if(maxNum < arr[i]){
                    maxNum = arr[i];
                    maxP = i;
                }
            }
            cnt -= maxNum;
            int ccnt = 0;
            //cout << i << "! " << endl;
            for(; i<=n; i++){
                //cout << cnt << " " << arr[i] << endl;
                if(cnt + arr[i] > s) break;
                cnt += arr[i];
                ccnt ++;
                //cout <<cnt;
            }
            if(ccnt >= 1) cout << maxP << endl;
            else cout << 0 << endl;
            
        
        }


        return 0;
    }