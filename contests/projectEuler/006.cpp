#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long int t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        long long int a, b;
        a = (long long int)pow((n * (n + 1))/2, 2);
        b = n * (n + 1) * (2*n + 1) / 6;
        cout<<abs(a - b)<<endl;
    }
    return 0;
}

