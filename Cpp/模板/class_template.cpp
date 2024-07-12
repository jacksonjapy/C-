//
// Created by jackson on 2024/7/5.
//
// 类模板
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class Box {
private:
    T content{};
public:
    void setContent(T c) {
        content = c;
    }
    T getContent() {
        return content;
    }
};

int main(){
    Box<int> box1;
    box1.setContent(10);
    cout << box1.getContent() << endl;

    Box<double> box2;
    box2.setContent(3.14);
    cout << box2.getContent() << endl;
    return 0;
}