#include <iostream>
#include <cstdio>
#include "string.hpp"
#include <cstring>

using namespace std;

bool test_length_empty() {
    char s_empty [] = "";
    String s(s_empty);
    return s.length() == 0;
}

bool test_at() {
    char s1 [] = "abcd";
    String s(s1);
    return s.at(1) == s1[1];
}

bool test_at_const() {
    char s1 [] = "abcd";
    const String s(s1);
    return s.at(1) == s1[1];
}

bool test_append() {
    char s1 [] = "abc";
    char s2 [] = "def";
    String s(s1);
    s.append(s2);
    char s3 [] = "abcdef";
    for (int i = 0; i < strlen(s3); i++)
        if (s.at(i) != s3[i])
            return false;
    return true;
}

bool test_raw() {
    char s1 [] = "abc";
    String s(s1);
    return s.length() == strlen(s1);
}

bool test_copy_constructor() {
    char st[] = "copy";
    String s1(st);
    String s2(s1);
    return s2.raw() != s1.raw();
}

bool test_copy_constructor2() {
    char st[] = "copy";
    String s1(st);
    String s2(s1);
    if (s1.length() != s2.length()) return false;
    for (int i = 0; i < s1.length(); i++)
        if (s1.at(i) != s2.at(i))
            return false;
    return true;
}

bool test_operator() {
    char str[] = "operator";
    String s1(str);
    String s2(nullptr);
    s2 = s1;
    s2.append(str);
    return s2.length() != s1.length();
}

int main(int argc, const char * argv[]) {
    cout << "test empty length: " << test_length_empty() << endl;
    cout << "test at: " << test_at() << endl;
    cout << "test at const: " << test_at_const() << endl;
    cout << "test append: " << test_append() << endl;
    cout << "test raw: " << test_raw() << endl;
    cout << "test copy constructor: " << test_copy_constructor() << ' ' << test_copy_constructor2() << endl;
    cout << "test operator: " << test_operator() << endl;
    return 0;
}
