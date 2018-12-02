#include <bits/stdc++.h>

using namespace std;

static int count_unfull(const string& s, uint64_t end){
    int result = 0;
    for (uint64_t i = 0; i< end; ++i){
        if(!s[i]){
            return result;
        }
        if (s[i] == 'a'){
            result++;
        }
    }
    return result;
}
// Complete the repeatedString function below.
uint64_t repeatedString(string s, uint64_t n) {
    return (n/s.size())*count_unfull(s, s.size()) +  count_unfull(s, n%s.size());
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    uint64_t n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    auto result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
