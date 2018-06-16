#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void sieve(int n, vector<bool> &SIEVE, vector<long int> &arr) {
    SIEVE[0] = SIEVE[1] = false;
    long int p;
    for(long int i = 2; i <= n; i++) {
        p = i;
        if(!SIEVE[p]) {
            SIEVE[p] = true;
            arr.push_back(p);
            for(int j = p; j <= n; j += p)
                SIEVE[j] = true;
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<bool> SIEVE(1000000, false);
    vector<long int> arr;
    sieve(1000000, SIEVE, arr);
    long int t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        cout<<arr[n-1]<<endl;
    }
    return 0;
}

