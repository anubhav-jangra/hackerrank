#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while(t--) {
        cin>>n;
        if(n < 3) {
            cout<<"-1\n";
            continue;
        }
        string str = "";
        int temp = n;
        for(int i = n/3; i >= 0; i--)
            for(int j = 0; j <= n/5; j++) {
                if(i * 3 + j * 5 == n) {
                    while(i--)
                        str += "555";
                    while(j--)
                        str += "33333";
                    break;
                }
            }
        if(str == "")
            cout<<-1<<endl;
        else
            cout<<str<<endl;
    }
    return 0;
}

