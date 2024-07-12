//
// Created by jackson on 2024/7/5.
//
#include <iostream>
#include <map>
using std::cout;
using std::endl;
using std::map;
using std::string;

int main() {
    map<int, string> myMap;
    myMap[1] = "One";
    myMap[2] = "Two";

    for (auto& pair : myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}