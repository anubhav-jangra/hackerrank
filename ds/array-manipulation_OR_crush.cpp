#include <bits/stdc++.h>

using namespace std;

// vector<string> split_string(string);

// // Complete the arrayManipulation function below.
// long arrayManipulation(int n, vector<vector<int>> queries) {
//     long int max_element = queries[0][2];
//     for(long int i = 1; i < queries.size(); i++) {
//         if(!(queries[i][0] > queries[i-1][1] || queries[i][1] < queries[i][0]))
//             max_element += queries[i][2];
//     }
//     return max_element;
// }

// // First attempt -> too slow O(n^2)
// /*
// // Complete the arrayManipulation function below.
// long arrayManipulation(int n, vector<vector<int>> queries) {
//     vector<long int> arr(n, 0);
//     for(long int i = 0; i < queries.size(); i++) {
//         for(j = queries[i][0]; j <= queries[i][1]; j++) {
//             arr[j] += queries[i][2];
//         }
//     }
//     long int max_element = arr[0];
//     for(long int i = 1; i < n; i++) {
//         if(arr[i] > max_element) {
//             max_element = arr[i];
//         }
//     }
//     return max_element;
// }
// */
// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     string nm_temp;
//     getline(cin, nm_temp);

//     vector<string> nm = split_string(nm_temp);

//     int n = stoi(nm[0]);

//     int m = stoi(nm[1]);

//     vector<vector<int>> queries(m);
//     for (int i = 0; i < m; i++) {
//         queries[i].resize(3);

//         for (int j = 0; j < 3; j++) {
//             cin >> queries[i][j];
//         }

//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     }

//     long result = arrayManipulation(n, queries);

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

// Found this on the forum
// Quiet a brilliant approach in T->O(n) & S->O(1)
int main() {
    long int n, q, a, b, k;
    cin>>n>>q;
    vector<long int> arr(n + 1, 0);
    while(q--) {
        cin>>a>>b>>k;
        arr[a] += k;
        if(b+1 <= n)
            arr[b+1] -= k;
    }
    a = 0;
    k = 0;
    for(long int i = 1; i <= n; i++) {
        k += arr[i];
        if(k > a)
            a = k;
    }
    cout<<a;
}
