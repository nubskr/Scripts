//It was mine for the taking, it was mine for a million days, in a million ways
#include <bits/stdc++.h>
using namespace std;
#define int long long
#ifdef DEBUG
#include</home/nubskr/debug.h>
#else
#define deb(...) 44
#define debv(a) 44
#endif
const int MOD = 1e9 + 7;


const int N = 105;

int a[N][N][2];
// 0 -> alice wins, 1 -> bob wins

int gogo(int cnteven,int cntodd,int parity,int turn){
    if(cntodd==0){
        return (parity);
    }
    int &ans = a[cnteven][cntodd][parity];
    if(ans==-1){
        int newturn = 1 - turn;
        int newparity = 1 - parity;
        if(turn&1){//bob's turn
            int try1,try2;   
            if(cnteven>0){
                try1 = gogo(cnteven-1,cntodd,parity,newturn);
            }
            if(cntodd>0){
                try2 = gogo(cnteven,cntodd-1,parity,newturn);
            }
            if(try1==0 || try2==0){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            int try1,try2;   
            if(cnteven>0){
                try1 = gogo(cnteven-1,cntodd,parity,newturn);
            }
            if(cntodd>0){
                try2 = gogo(cnteven,cntodd-1,newparity,newturn);
            }
            if(try1==1 || try2==1){
                return 1;
            }
            else{
                return 0;
            }
        }   
    }
    return ans;
}

int32_t main(){ios::sync_with_stdio(0); cin.tie(0); // think smol then think big, and use functions above this
// nl prohibited
// PLAN PLAN PLAN.....
auto solve = [&]() {
    memset(a,-1,sizeof(a));
    int n;
    cin >> n;
    int cnt0 = 0,cnt1 = 0;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        cnt1 += (a&1);
        cnt0 += !(a&1);
    }
    cout << (gogo(cnt0,cnt1,1,0) ? "Alice" : "Bob") << endl;
};

int t = 1;
cin >> t;

while(t--){solve();}
cerr << "\nTime Elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
