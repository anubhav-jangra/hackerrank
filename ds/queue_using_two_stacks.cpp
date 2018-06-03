#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    stack<int> st1;
    stack<int> st2;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        int choice;
        cin>>choice;
        if(choice == 1) {
                int val;
                cin>>val;
                st1.push(val);
        } else {
            if(st2.empty()) {
                while(!st1.empty()) {
                    st2.push(st1.top());
                    st1.pop();
                }
            }
            if(choice == 3)
                cout<<st2.top()<<endl;
            else
                st2.pop();
        }
    }
    return 0;
}

