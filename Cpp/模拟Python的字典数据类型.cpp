//
// Created by jackson on 2024/7/5.
//
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // 创建一个类似Python字典的容器
    std::unordered_map<std::string, int> my_dict;

    // 插入键值对
    my_dict["apple"] = 1;
    my_dict["banana"] = 2;
    my_dict["cherry"] = 3;

    // 访问元素
    std::cout << "Value of 'apple': " << my_dict["apple"] << std::endl;
    std::cout << "Value of 'banana': " << my_dict["banana"] << std::endl;

    // 检查是否包含某个键
    if (my_dict.find("cherry") != my_dict.end()) {
        std::cout << "'cherry' is in the dictionary." << std::endl;
    }

    // 遍历字典
    for (const auto &pair: my_dict) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    // 删除一个键值对
    my_dict.erase("banana");

    // 再次遍历字典
    for (const auto &pair: my_dict) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    return 0;
}
