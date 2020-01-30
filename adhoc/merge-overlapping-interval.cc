#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the getMergedIntervals function below.
 */
vector<vector<int> > getMergedIntervals(vector<vector<int> > inputArray) {
  if (inputArray.size() <= 1) {
    return inputArray;
  }
  /*
   * Write your code here.
   */
  vector<vector<int>> result;

  vector<pair<int, int> > arr;
  for (auto i: inputArray) {
    arr.push_back(make_pair(i[0], i[1]));
  }
  sort(arr.begin(), arr.end(),
       [](const pair<int, int> &left, const pair<int, int>& right) {
          return left.first < right.first; });
  int i = 1;
  pair<int, int> ci = arr[0];
  while (i < arr.size()) {
    if (arr[i].first <= ci.second) {
      if (arr[i].second > ci.second) {
        ci.second = arr[i].second;
      }
    } else {
      vector<int> intvl = {ci.first, ci.second};
      result.push_back(intvl);
      ci =  arr[i];
    }
    i++;
  }
  vector<int> intvl = {ci.first, ci.second};
  result.push_back(intvl);
  return result;
}

int main()
{
    ostream &fout = cout;

    int inputArray_rows;
    cin >> inputArray_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int inputArray_columns;
    cin >> inputArray_columns;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> inputArray(inputArray_rows);
    for (int inputArray_row_itr = 0; inputArray_row_itr < inputArray_rows; inputArray_row_itr++) {
        inputArray[inputArray_row_itr].resize(inputArray_columns);

        for (int inputArray_column_itr = 0; inputArray_column_itr < inputArray_columns; inputArray_column_itr++) {
            cin >> inputArray[inputArray_row_itr][inputArray_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<vector<int>> res = getMergedIntervals(inputArray);

    for (int res_row_itr = 0; res_row_itr < res.size(); res_row_itr++) {
        for (int res_column_itr = 0; res_column_itr < res[res_row_itr].size(); res_column_itr++) {
            fout << res[res_row_itr][res_column_itr];

            if (res_column_itr != res[res_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (res_row_itr != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";



    return 0;
}
