//
// Created by jackson on 2024/7/5.
//
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;


int main() {
    // 初始化一个整数向量，用于存储一系列数字
    vector<int> numbers;

    // 向向量中添加数字1
    numbers.push_back(1);
    // 向向量中添加数字2
    numbers.push_back(2);
    // 向向量中添加数字3
    numbers.push_back(3);

    // 遍历向量中的每个数字并打印
    for (int num: numbers) {
        cout << num << endl;
    }
}