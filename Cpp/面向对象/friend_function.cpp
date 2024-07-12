//
// Created by jackson on 2024/7/5.
//
#include <iostream>
using std::cout;
using std::endl;

class Box {
private:
    double width{12.0};

public:
    friend void printWidth(Box box);
    void setWidth(double w) {
        width = w;
    }
};

void printWidth(Box box) {
    cout << "Width: " << box.width << " cm" << endl;
}

int main(){
    Box box;
    box.setWidth(10.0);
    printWidth(box);
    return 0;
}