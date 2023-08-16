#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

string balancedSumsAlt(vector<int> arr) {
    for(int i = 0; i < arr.size(); i++) {
        int sumA = accumulate(arr.begin(), arr.begin() + i, 0);
        int sumB = accumulate(arr.begin() + i + 1, arr.end(), 0);
        cout << i << " -> " << sumA << ":" << sumB << endl ;
        if(sumA == sumB){
            cout << "Equal" << endl ;
            return "YES";
        } else {
            cout << "Not equal" << endl ;
        }
    }
    return "NO";
}

string balancedSums(vector<int> arr) {
    long totalSum = accumulate(arr.begin() + 1, arr.end(), 0);
    long rightSum = totalSum;
    long leftSum = 0;
    
    if(rightSum == 0) return "YES";

    for(int i = 1; i < arr.size(); i++) {
        rightSum -= arr[i];
        leftSum += arr[i - 1];
        if(leftSum == rightSum) return "YES";
    }
    return "NO";
}

int main()
{
    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        string result = balancedSums(arr);

        cout << result << endl;
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c);})
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](int c) {return !std::isspace(c);}).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
