#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t, n, a, b, c;
    long long int temp, ans;
    cin>>t;
    while(t--) {
        ans = -1;
        cin>>n;
        for(int a = 1; a < n; a++) {
            int b = (2*n*a - n*n) / (2*a - 2*n);
            int c = n - a - b;
            if(a*a + b*b == c*c && b > 0) {
                temp = a*b*c;
                if(temp > ans)
                    ans = temp;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

