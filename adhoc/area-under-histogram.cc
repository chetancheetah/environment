#include <bits/stdc++.h>

using namespace std;

long long int findMaxPossibleArea(vector<long long int> heights, int l, int r) {
  stack<int> s;
  long long int max_area = 0;
  int i = 0;
  for (i = l; i <= r;) {
    if (s.empty() || heights[s.top()] <= heights[i]) {
      //cout << "push " << i << endl;
      s.push(i++);
    } else {
      int top = s.top();
      s.pop();
      long long int area = heights[top] * (s.empty() ? i - l : i - s.top() - 1);
      max_area = max(max_area, area);
      //cout << "pop " << top << " area " << area << " max area " << max_area << endl;
    }
  }

  while (!s.empty()) {
    int top = s.top();
    s.pop();
    long long int area = heights[top] * (s.empty() ? i - l : i - s.top() - 1);
    max_area = max(max_area, area);
      //cout << "Pop " << heights[top] << " area " << area << " max area " << max_area << endl;
  }
  return max_area;
}

int main()
{
    ostream &fout = cout;

    int heights_count;
    cin >> heights_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<long long int> heights(heights_count);

    for (int heights_itr = 0; heights_itr < heights_count; heights_itr++) {
        long long int heights_item;
        cin >> heights_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        heights[heights_itr] = heights_item;
    }

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < q; ++i)
    {
        int l;
        cin >> l;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int r;
        cin >> r;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long long int res = findMaxPossibleArea(heights, l, r);

        fout << res << "\n";
    }

    return 0;
}
