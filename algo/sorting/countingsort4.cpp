#include <bits/stdc++.h>

using namespace std;

int main() {
    long int n, i;
    int x;
    cin>>n;
    map <int, string> mp;
    string str;
    for(i = 0; i < n/2; i++) {
        cin>>x;
        cin>>str;
        if ( mp.find(x) != mp.end() ) {
            mp[x] += " -";
        } else {
            mp[x] = "-";
        }
    }
    for(i; i < n; i++) {
        cin>>x;
        cin>>str;
        if ( mp.find(x) != mp.end() ) {
            mp[x] += " " + str;
        } else {
            mp[x] = str;
        }
    }
    map <int, string> :: iterator itr;
    for (itr = mp.begin(); itr != mp.end(); ++itr)
    {
        cout<<itr->second<<" ";
    }
}
