// better solution would have been to make an array of 26 X 23

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<vector<int> > vec(20, vector<int>(20));
    long long int ans = -1, temp;
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 20; j++)
            cin>>vec[i][j];
    for(int i = 0; i < 17; i++)
        for(int j = 0; j < 17; j++) {
            temp = vec[i][j] * vec[i][j+1] * vec[i][j+2] * vec[i][j+3];
            if(temp > ans)
                ans = temp;
            temp = vec[i][j] * vec[i+1][j] * vec[i+2][j] * vec[i+3][j];
            if(temp > ans)
                ans = temp;
            temp = vec[i][j] * vec[i+1][j+1] * vec[i+2][j+2] * vec[i+3][j+3];
            if(temp > ans)
                ans = temp;
            if(i >= 3) 
                temp = vec[i][j] * vec[i-1][j+1] * vec[i-2][j+2] * vec[i-3][j+3];
            if(temp > ans)
                ans = temp;
        }
    for(int i = 17; i < 20; i++)
        for(int j = 0; j < 17; j++) {
            temp = vec[i][j] * vec[i][j+1] * vec[i][j+2] * vec[i][j+3];
            if(temp > ans)
                ans = temp;
        }
    for(int i = 0; i < 17; i++)
        for(int j = 17; j < 20; j++) {
            temp = vec[i][j] * vec[i+1][j] * vec[i+2][j] * vec[i+3][j];
            if(temp > ans)
                ans = temp;
        }
    cout<<ans;
    return 0;
}

