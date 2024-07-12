//
// Created by jackson on 2024/7/5.
//
#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::list;

int main(){
    list<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    for (int num : numbers) {
        cout << num << endl;
    }
}