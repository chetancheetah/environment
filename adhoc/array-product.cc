#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
vector<int> getProductArray_bruteforce(vector<int> nums) {
    // Write your code here.
    vector<int> products(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (i == j) continue;
            products[i] *= nums[j];
        }
    }
    return products;
}

vector<int> getProductArray(vector<int> nums) {
    // Write your code here.
    vector<int> products(nums.size(), 1);
    int lprod = 1;
    for (int i = 0; i < nums.size(); i++) {
        products[i] = lprod;
        lprod *= nums[i];
    }
    int rprod = 1;
    for (int j = nums.size() - 1; j >= 0; j--) {
        products[j] *= rprod;
        rprod *= nums[j];
    }
    return products;
}

int main()
{
    ostream &fout = cout;

    int nums_size;
    cin >> nums_size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> nums(nums_size);
    for (int nums_i = 0; nums_i < nums_size; nums_i++) {
        int nums_item;
        cin >> nums_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        nums[nums_i] = nums_item;
    }

    vector<int> res = getProductArray(nums);

    for (int res_itr = 0; res_itr < res.size(); res_itr++) {
        fout << res[res_itr];

        if (res_itr != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    return 0;
}
