#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    short t, k, n;
    long long int maxx, ans;
    cin>>t;
    char c;
    while(t--) {
        ans = -1;
        cin>>n>>k;
        vector<short> vec(n);
        for(int i = 0; i < n; i++) {
            cin>>c;
            vec[i] = static_cast<int>(c) - 48;
        }
        for(int i = k-1; i < n; i++) {
            maxx = vec[i-(k-1)];
            for(int j = i - k + 2; j <= i; j++)
                maxx *= vec[j];
            if(maxx > ans)
                ans = maxx;
        }
        cout<<ans<<endl;
    }
    return 0;
}

