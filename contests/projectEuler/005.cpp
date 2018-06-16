#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void sieve(int n, vector<bool> &SIEVE, vector<pair<int, int>> &primes) {
    SIEVE[0] = SIEVE[1] = false;
    int p;
    for(int i = 2; i <= n; i++) {
        p = i;
        if(!SIEVE[p]) {
            SIEVE[p] = true;
            primes.push_back(make_pair(p, floor( log(n)/log(p) ) ));
            for(int j = p; j <= n; j += p) {
                SIEVE[j] = true;
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t, n, prod;
    cin>>t;
    while(t--) {
        prod = 1;
        vector<bool> SIEVE(n+1, false);
        vector<pair<int, int>> primes;
        cin>>n;
        sieve(n, SIEVE, primes);
        for(int i = 0; i < primes.size(); i++)
            prod *= (int)pow(primes[i].first, primes[i].second);
        cout<<prod<<endl;
    }
    return 0;
}

