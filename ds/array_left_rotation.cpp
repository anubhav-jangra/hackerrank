    #include <bits/stdc++.h>

using namespace std;

vector<int> leftRotate(vector<int> a, int d) {
    vector<int> temp;
    for(int i = 0; i < d; i++)
        temp.push_back(a[i]);
    for(int i = 0; i < a.size() - d; i++)
        a[i] = a[i + d];
    for(int i = a.size() - d; i < a.size(); i++)
        a[i] = temp[i + d - a.size()];
    return a;
}

int main()
{
    int n, d;
    cin>>n>>d;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin>>a[i];

    a = leftRotate(a, d);
    for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<" ";
    return 0;
}

