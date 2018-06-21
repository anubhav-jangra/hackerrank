#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void sieve(int n, vector<bool> &SIEVE, vector<int> &arr) {
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
    vector<bool> SIEVE(10000000, false);
    vector<int> arr;
    sieve(10000000, SIEVE, arr);
    int t;
    long long int a, n;
    cin>>t;
    while(t--) {
        a = 0;
        cin>>n;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > n)
                break;
            a += arr[i];
        }
        cout<<a<<endl;
    }
    return 0;
}

