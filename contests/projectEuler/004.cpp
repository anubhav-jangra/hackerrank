#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int size_num(int n) {
    int count = 0;
    while(n) {
        count++;
        n /= 10;
    }
    return count;
}

bool isPalindrome(long int n) {
    int arr[6];
    for(int i = 0; i < 6; i++) {
        arr[i] = n%10;
        n /= 10;
    }
    for(int i = 0; i < 3; i++) {
        if(arr[i] != arr[5-i])
            return false;
    }
    return true;
}

bool stuff(long int n) {
    for(int i = 101; i < 999; i++) {
        if(n % i == 0) {
            if(size_num(n/i) == 3)
                return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    long int n;
    for(int a0 = 0; a0 < t; a0++){
        cin >> n;
        for(long int i = n-1; i >= 101101; i--) {
            if(isPalindrome(i)) {
                if(stuff(i)) {
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
