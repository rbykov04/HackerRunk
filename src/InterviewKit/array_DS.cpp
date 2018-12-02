#include <bits/stdc++.h>

using namespace std;

int hourglass_1_sum(const vector<vector<int> >& arr, int x, int y){

    return arr[y+0][x+0] + arr[y+0][x+1] + arr[y+0][x+2]
                         + arr[y+1][x+1] +
           arr[y+2][x+0] + arr[y+2][x+1] + arr[y+2][x+2];       
}
// Complete the hourglassSum function below.
int hourglassSum(const vector<vector<int> >& arr) {
    int result = INT_MIN;
    //only for matrix 6 on 6
    for (int i = 0; i<4; ++i)
        for(int j = 0; j<4; ++j){
            result = max(result, hourglass_1_sum(arr, i, j));
        }

    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int> > arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
