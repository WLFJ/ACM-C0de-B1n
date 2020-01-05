    #include<iostream>
    using namespace std;
    typedef unsigned long long ull;
    int main(void){
        int t;
        cin >> t;
        while(t --){
            int n;
            cin >> n;
            ull sum = 0, num,Xor = 0;
            while(n --){
                cin >> num;
                sum += num;
                Xor ^= num;
            }
            cout << 2 << "\n" << Xor << " " << sum + Xor << endl;
        }
        return 0;
     
    }