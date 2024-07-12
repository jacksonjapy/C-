//
// Created by jackson on 2024/7/5.
//
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main(){
    // 初始化一个包含1到5的整数的向量
    vector<int> numbers = {1, 2, 3, 4, 5};
    // 定义一个向量迭代器
    vector<int>::iterator it;

    // 遍历向量中的每个元素并打印
    for (it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}