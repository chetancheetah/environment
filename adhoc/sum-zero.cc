#include <bits/stdc++.h>

using namespace std;

// Complete the sumZero function below.
vector<int> sumZero(vector<int> arr) {
  unordered_map<long long, int> sum_map;
  long long sum = 0;
  vector<int> result;
  for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];
    if (!arr[i]) {
      result.push_back(i);
      result.push_back(i);
      break;
    }
    if (!sum) {
      result.push_back(0);
      result.push_back(i);
      break;
    }
    unordered_map<long long, int>::iterator it = sum_map.find(sum);
    if (it != sum_map.end()) {
      //cout << "Found sum " << sum << " : (" << it->second << ", " << i << ")\n";
      result.push_back(it->second + 1);
      result.push_back(i);
      break;
    } else {
      //cout << "Inserting sum " << sum << " : " << i << endl;
      sum_map.insert(make_pair(sum, i));
    }
  }
  if (!result.size()) {
    result.push_back(-1);
  }
  return result;
}

int main()
{
    ostream &fout = cout;

    int arr_count;
    cin >> arr_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    vector<int> res = sumZero(arr);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";



    return 0;
}
