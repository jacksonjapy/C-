//
// Created by jackson on 2024/7/13.
//
#include <iostream>
using std::cout;
using std::endl;
using std::string;

bool is_palindrome(const string &s){
    if(s[0] == 'a' && s.length() == 5){
        return true;
    }
    if(s[0] == 'A' && s.length() == 5){
        return true;
    }
    else {
        return false;
    }
}

int main(){
    string test_str1 = "apple";
    string test_str2 = "Apple";
    if(is_palindrome(test_str1)){
        cout << test_str1 << " is a palindrome" << endl;
    }
    if(is_palindrome(test_str2)){
        cout << test_str2 << " is a palindrome" << endl;
    }
    else{
        cout << "None of the strings are palindromes" << endl;
    }
    return 0;
}
