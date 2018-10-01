#include <cmath>
#include <stack>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    int sum = 0, carry = 0;
    stack<int> stk;
    for(int j = 49; j >= 0; j--) {
        sum = carry;
        for(int i = 0; i < n; i++) {
            sum += (int(arr[i][j]) - 48);
        }
        stk.push(sum % 10);
        carry = sum / 10;
    }
    while(carry != 0) {
        stk.push(carry%10);
        carry /= 10;
    }
    for(int i = 0; i < 10; i++) {
        cout<<stk.top();
        stk.pop();
    }
    return 0;
}

