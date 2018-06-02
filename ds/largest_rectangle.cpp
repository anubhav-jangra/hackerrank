#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Now pulling off the big guns .... O(n) using stacks implementation....

long largestRectangle(vector<int> a) {
    vector<int> vec;
    long int ar = 0, temp, temp1, i = 0;
    while(i < a.size())
    {
        if(vec.empty() || a[vec.back()] <= a[i]) {
            vec.push_back(i++);
        } else {
            temp1 = vec.back();
            vec.pop_back();
            temp = a[temp1] * (vec.empty() ? i : i - vec.back() - 1);
            cout<<"temp area is -> "<<temp<<endl;
            if(temp > ar)
                ar = temp;
        }
    }
    while (!vec.empty())
    {
        temp1 = vec.back();
        vec.pop_back();
        temp = a[temp1] * (vec.empty() ? i : i - vec.back() - 1);
        cout<<"temp area is -> "<<temp<<endl;
        if(temp > ar)
                ar = temp;
    }
    return ar;
}
/*
// This small code works out on all the test cases and guess what 
// i came by it all by myself ... ;)

// it's order is i suppose O(n^2) as well but that is the worst case scenario
// else it's okay i guess

long largestRectangle(vector<int> a) {
    long int ar = 0, temp = 0, j;
    for(int i = 0; i < a.size(); i++) {
        int is, ie;
        for(j = i - 1; j >= 0 && a[j] >= a[i]; j--) {}
        is = j + 1;
        for(j = i + 1; j < a.size() && a[j] >= a[i]; j++) {}
        ie = j - 1;
        cout<<"is -> "<<is<<" ie -> "<<ie<<endl;
        temp = (ie - is + 1)*a[i];
        cout<<"temp -> "<<temp<<endl;
        if(temp > ar)
            ar = temp;
    }
    return ar;
}
*/
// ==========================================
// for O(nlogn) using segmentTree
// class SegmentTree {
//     private:
//         int n;          // size of array for which ST is to be formed
//         int h;          // height of ST
//         int max_size;   // max size of array for the segment tree
//         vector<int> st; // array for ST
//         vector<int> hist;   // array of the histogram given

//         int getMid(int s, int e) { return s + (e - s)/2; }
    
//         int minVal(int a, int b) { 
//             if(a == -1) return b;
//             if(b == -1) return a;
//             return hist[a] > hist[b] ? b : a; 
//         }

//         int constructSTUtil(int ss, int se, int si) {
//             // cout<<"ss -> "<<ss<<" se -> "<<se<<" si -> "<<si<<endl;
//             // If there is one element in array, store it in current node of
//             // segment tree and return
//             if(ss == se) {
//                 this->st[si] = ss;
//                 return ss;
//             }
            
//             // If there are more than one elements, then recur for left and
//             // right subtrees and store the minimum of two values in this node
//             int mid = this->getMid(ss, se);
//             this->st[si] = minVal(this->constructSTUtil(ss, mid, 2*si + 1), 
//                                this->constructSTUtil(mid+1, se, 2*si + 2));
//             // this is where you modify to get desired ST results
//             return this->st[si];
//         }
//         int RMQUtil(int ss, int se, int qs, int qe, int si) {
//             cout<<"ss -> "<<ss<<" se -> "<<se<<" si -> "<<si<<endl;
//             // If segment of this node is a part of given range, then return
//             //  the min of the segment
//             if(qs <= ss && qe >= se)
//                 return this->st[si];
//             if(se < qs || ss > qe)
//                 return -1;;
//             int mid = this->getMid(ss, se);
//             return minVal(this->RMQUtil(ss, mid, qs, qe, 2*si + 1),
//                           this->RMQUtil(mid+1, se, qs, qe, 2*si + 2));
//         }

//     public:
//         SegmentTree(vector<int> arr) {      // to initialize the ST(formation)
//             this->hist = arr;
//             this->n = arr.size();
//             this->h = (int)ceil(log2(n));
//             this->max_size = 2*(int)pow(2, h) - 1;
//             for(int i = 0; i < max_size; i++)
//                 this->st.push_back(-1);
//             this->constructSTUtil(0, n-1, 0);
//         }
    
//         int RMQ(int qs, int qe) {
//             cout<<"RMQ called with qs -> "<<qs<<" qe -> "<<qe<<endl;
//             // Check for erroneous input values
//             if(qs < 0 || qe > n - 1 || qs > qe) {
//                 cout<<"Invalid Input\n";
//                 return -1;
//             }
//             return this->RMQUtil(0, n - 1, qs, qe, 0);
//         }
// };

// // for recursive O(n^2)
// // int min_height_index(vector<int> A, int i, int j)
// // {
// //     int h = j;
// //     for(int t = i; t < j; t++)
// //     {
// //         if(A[t] < A[h])
// //             h = t;
// //     }
// //     return h;
// // }

// int doStuff(vector<int> A, int i, int j, SegmentTree segTree)
// {
//     cout<<"i is -> "<<i<<" j is -> "<<j<<endl;
//     if(i > j) {
//         cout<<"returned -1"<<endl;
//         return -1;
//     }
//     if(i == j) {
//         cout<<"returned "<<A[i]<<endl;
//         return A[i];
//     }
//     int h1, h2, a1, a2, a;
//     // int h = min_height_index(A, i, j);
//     int h = segTree.RMQ(i, j);
//     cout<<"h is -> "<<h<<endl;
//     a1 = doStuff(A, i, h - 1, segTree);
//     a2 = doStuff(A, h + 1, j, segTree);
//     a = A[h] * (j - i + 1);
//     cout<<"returned max("<<a<<", max("<<a1<<", "<<a2<<")) -> "<<max(a, max(a1, a2))<<endl;
//     return max(a, max(a1, a2));
// }

// long largestRectangle(vector<int> a) {
//     SegmentTree segTree(a);
//     return doStuff(a, 0, a.size() - 1, segTree);
// }

// ===============================================
// Complete the largestRectangle function below.
// O(n^2) -> simple iterative version
// long largestRectangle(vector<int> a) {
//     long ar = 0;
//     for(int i = 0; i < a.size(); i++)
//     {
//         int j, ti = 0, tf = 0;
//         for(j = 0; j < a.size(); j++)
//         {
//             if(a[j] < a[i])
//             {
//                 cout<<"a[j] is < a[i]\n";
//                 if(j < i) {
//                     ti = j + 1;
//                     continue;
//                 } else {
//                     tf = j;
//                     break;
//                 }
//             }
//         }
//         if(j == a.size()) {
//             tf = j;
//             cout<<"j reached the end\n";
//         }
//         if(ar < (tf - ti) * a[i])
//             ar = (tf - ti) * a[i];
//     }
//     return ar;
// }

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);
    
    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}


// someone else's solution
// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;


// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
//    long long n,arr[100001],i,j,max,temp=-1,k,count=1,val;
//     cin>>n;
//     for(i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     for(i=0;i<n;i++){
//         val=arr[i];
//       int cl1=1,cl=1;
//         for(j=i-1,k=i+1;j>=0 || k<n;j--,k++){
//             if(j>=0 && arr[j]>=val && cl1==1){
//                 count++;
//             }else cl1=0;
//             if(k<n && arr[k]>=val && cl==1){
//                 count++;
//             }else cl=0;
//             if(cl==0 && cl1==0)
//                 break;
//         }
//         max=val*count;
//         if(max>temp){
//             temp=max;
//         }
//         count=1;
        
//     }
//     cout<<temp;
//     return 0;
// }

