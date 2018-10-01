#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<long long int>primeFactors(long long int n) {
    vector<long long int> vec;
    while (n%2 == 0) {
        vec.push_back(2);
        n = n/2;
    }
    for (long long int i = 3; i <= sqrt(n); i = i+2) {
        while (n%i == 0) {
            vec.push_back(i);
            n = n/i;
        }
    }
    if (n > 2)
        vec.push_back(n);
    return vec;
}

int main() {
    long long int n;
    short t;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<long long int> arr(primeFactors(n));
        cout<<arr.back()<<endl;
    }
    return 0;
}

