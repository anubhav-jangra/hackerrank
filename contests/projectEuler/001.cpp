#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long int doStuff(long int n, short a) {
    return (a * n * (n+1))/2;
}

int main() {
    int t;
    cin>>t;
    long int n, n1, n2, n3;
    while(t--) {
        cin>>n;
        n1 = (n-1)/3;
        n2 = (n-1)/5;
        n3 = (n-1)/15;
        cout<< doStuff(n1, 3) + doStuff(n2, 5) - doStuff(n3, 15)<<endl;
    }
    return 0;
}

