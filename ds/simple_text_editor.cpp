#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


int main() {
    vector<char> st;
    stack<string> record;
    stack<char> arrange;
    int q, choice, k;
    string str, temp;
    cin>>q;
    while(q--) {
        cin>>choice;
        switch(choice) {
            case 1:
                temp = "1 ";
                cin>>str;
                temp += str;
                for(int i = 0; i < str.length(); i++)
                    st.push_back(str[i]); 
                record.push(temp);
                break;
            case 2:
                temp = "2 ";
                cin>>k;
                while(k--) {
                    arrange.push(st.back());
                    st.pop_back();
                }
                while(!arrange.empty()) {
                    temp += arrange.top();
                    arrange.pop();
                }
                record.push(temp);
                break;
            case 3:
                cin>>k;
                cout<<st[k-1]<<endl ;
                break;
            case 4:
                if(record.empty())
                    break;
//                 1 pushed a string str....still intact;
//                 2 removed last few k elements(k intact) strore the remove items
                temp = record.top();
                // cout<<"temp is -> "<<temp<<endl;
                if(temp[0] == '1') {
                    for(int i = 2; i < temp.length(); i++)
                        st.pop_back();
                } else if(temp[0] == '2') {
                    for(int i = 2; i < temp.length(); i++) 
                        st.push_back(temp[i]);
                }
                record.pop();
        }
    }
    
    return 0;
}

