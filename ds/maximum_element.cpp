#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> arr;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        int q;
        cin>>q;
        switch(q)
        {
            case 1:
                int a;
                cin>>a;arr.push_back(a);
                break;
            case 2:
                arr.pop_back();
                break;
            case 3:
                int max = arr[0];
                for(int j = 1; j < arr.size(); j++)
                    if(max < arr[j])
                        max = arr[j];
                cout<<max<<endl;
        }
    }
    return 0;
}
