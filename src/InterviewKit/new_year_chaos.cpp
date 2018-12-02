#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
int how_many_briebs(const vector<int>& q, int i){
    int number = i + 1;
    if (q[i] == number) return 0;
    if (number<1) return 3;
    if (q[i-1] == number) return 1;
    if (number<3) return 3;
    if (q[i-2] == number) return 2;
    return 3;

}
void rot2(vector<int>& q, int i){
    swap(q[i-2], q[i-1]);
    swap(q[i-1], q[i]);
}

// Complete the minimumBribes function below.
int minimumBribes(vector<int>& q) {
    int result = 0;
    for (int i =q.size() -1; i >= 0; --i){
        int briebs = how_many_briebs(q, i);
        if (briebs == 3) return -1;
        if (briebs == 2){
            rot2(q, i);
        }else if (briebs == 1){
            swap(q[i-1], q[i]);
        }
        result += briebs;
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    ofstream fout(getenv("OUTPUT_PATH"));
    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        int r = minimumBribes(q);
        if (r < 0){
            fout<<"Too chaotic\n";
            continue;
        }
        fout<<r<<"\n";

    }

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
