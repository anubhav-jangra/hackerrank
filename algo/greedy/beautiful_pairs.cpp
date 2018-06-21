// #include <bits/stdc++.h>

// using namespace std;

// vector<string> split_string(string);

// int binarySearch(const vector<int> &arr, int x, int min, int max)
// {
//     if(min > max)
//         return -1;
//     int mid = (min + max) / 2;
//     if(arr[mid] == x)
//         return mid;
//     else if(arr[mid] > x)
//         return binarySearch(arr, x, min, mid - 1);
//     else
//         return binarySearch(arr, x, mid + 1, max);
//     return -1;
// }

// // Complete the beautifulPairs function below.
// int beautifulPairs(vector<int> A, vector<int> B) {
//     sort(A.begin(), A.end());
//     sort(B.begin(), B.end());
//     vector<bool> vec(A.size(), false);
//     int t = A.size();
//     for(int i = 0; i < A.size(); i++) {
//         for(int j = i+1; j < A.size(); j++) {
//             if(A[j] == A[i]) {
//                 A[j] = -1;
//                 t--;
//             }
//             else {
//                 i += j - i - 1;
//                 break;
//             }
//         }
//     }
//     cout<<"t is -> "<<t<<endl;
//     int counter = 0;
//     for(int i = 0; i < A.size(); i++) {
//         if(A[i] != -1) {
//             int s = binarySearch(B, A[i], 0, B.size()-1);
//             if(s != -1) {
//                 cout<<"("<<i<<", "<<s<<") added\n";
//                 counter++;
//                 vec[i] = true;
//             }
//             for(int p = 1; p < A.size(); p++) {
//                 if(A[i+p] == -1 && (B[s+p] == B[s] || B[s-p] == B[s])) {
//                     cout<<"("<<i+p<<", "<<s+p<<" or "<<s-p<<") added\n";
//                     counter++;
//                     vec[i+p] = true;
//                 } else
//                     break;
//             }
//         }
//     }
//     for(int i = 0; i < A.size(); i++) {
//         cout<<A[i]<<" ";
//     }
//     cout<<endl;
//     for(int i = 0; i < B.size(); i++) {
//         cout<<B[i]<<" ";
//     }
//     if(counter < A.size())
//         return counter+1;
//     return counter-1;
// }

// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     int n;
//     cin >> n;
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');

//     string A_temp_temp;
//     getline(cin, A_temp_temp);

//     vector<string> A_temp = split_string(A_temp_temp);

//     vector<int> A(n);

//     for (int i = 0; i < n; i++) {
//         int A_item = stoi(A_temp[i]);

//         A[i] = A_item;
//     }

//     string B_temp_temp;
//     getline(cin, B_temp_temp);

//     vector<string> B_temp = split_string(B_temp_temp);

//     vector<int> B(n);

//     for (int i = 0; i < n; i++) {
//         int B_item = stoi(B_temp[i]);

//         B[i] = B_item;
//     }

//     int result = beautifulPairs(A, B);

//     fout << result << "\n";

//     fout.close();

//     return 0;
// }

// vector<string> split_string(string input_string) {
//     string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
//         return x == y and x == ' ';
//     });

//     input_string.erase(new_end, input_string.end());

//     while (input_string[input_string.length() - 1] == ' ') {
//         input_string.pop_back();
//     }

//     vector<string> splits;
//     char delimiter = ' ';

//     size_t i = 0;
//     size_t pos = input_string.find(delimiter);

//     while (pos != string::npos) {
//         splits.push_back(input_string.substr(i, pos - i));

//         i = pos + 1;
//         pos = input_string.find(delimiter, i);
//     }

//     splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

//     return splits;
// }

// AMAZING SOLUTION using sieve approach kinda
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int a[1003]={0};
    int b[1003]={0};
    int n,x;
    cin>>n;
    int a1[n],b1[n];
    for(int i=0;i<n;i++){
        cin>>x;
        a[x]++;
    }
    for(int i=0;i<n;i++){
        cin>>x;
        b[x]++;
    }
    int c=0;
    for(int i=0;i<1002;i++){
        if(a[i]>0&&b[i]>0){
            c+=(min(a[i],b[i]));
        }
    }
    if(c<n){
        cout<<c+1<<endl;
    }
    else {
        cout<<c-1<<endl;
    }
    return 0;
}
