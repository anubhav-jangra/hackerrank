#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    unordered_map<char, char> umap;
    umap['('] = ')';
    umap['{'] = '}';
    umap['['] = ']';
    vector<char> vec;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '{' || s[i] == '(' || s[i] == '[')
            vec.push_back(s[i]);
        else {
            if(vec.empty() == false)
            {
                cout<<"Vec back -> "<<vec.back()<<endl;
                if( umap[vec.back()] == s[i] )
                    vec.pop_back();
                else
                    return "NO";
            }
            else
                return "NO";
        }
    }
    if(vec.empty())
        return "YES";
    else
        return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

