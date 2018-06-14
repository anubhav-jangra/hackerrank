#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    long long int n, f1, f2, sum;
    while(t--) {
        cin>>n;
        f1 = 1;
        f2 = 2;
        sum = 0;
        for(long long int i = 0; f2 < n; i++) {
            if(f2 % 2 == 0) {
                sum += f2;
            }
            swap(f1, f2);
            f2 = f1 + f2;
        }
        cout<<sum<<endl;
    }
    return 0;
}
