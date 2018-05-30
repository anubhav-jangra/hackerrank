#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    int n = (s[0] - 48)* 10 + (s[1] - 48);
    if(s[8] == 'P' && n != 12)
    {
        n += 12;
        s[0] = n / 10 + 48;
        s[1] = n % 10 + 48;
    }
    else if(s[8] == 'A' && n == 12)
    {
        s[0] = 48;
        s[1] = 48;
    }
    s.pop_back();
    s.pop_back();
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

