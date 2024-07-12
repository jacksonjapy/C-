//
// Created by jackson on 2024/7/5.
//
#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main(){
    vector<int> numbers = {5, 3, 1, 4, 2};
    sort(numbers.begin(), numbers.end());

    for (int num : numbers) {
        cout << num << endl;
    }
}