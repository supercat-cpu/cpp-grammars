#include <iostream>
#include <cstdio>
#include "string.hpp"
#include <cstring>
using namespace std;


bool test_nullptr() {
    char *s1 = nullptr;
    String s(s1);
    return s.raw() == s1;
}

bool test_length() {
    char s1 [10] = {'K', 'o', 'r' , 'n', 'y', 'k', 'h', 'y', 'n', '\0'};
    String s(s1);
    return s.length() == strlen(s1);
}

bool test_at() {
    char s1 [10] = {'K', 'o', 'r' , 'n', 'y', 'k', 'h', 'y', 'n', '\0'};
    String s(s1);
    return s.at(1) == s1[1];
}

bool test_append() {
    char s1 [10] = {'K', 'o', 'r' , 'n', 'y', 'k', 'h', 'y', 'n', '\0'};
    char s2 [7] = {'E', 'v', 'g', 'e', 'n', 'y', '\0'};
    String s(s1);
    s.append(s2);
    char s3 [17] = {'K', 'o', 'r' , 'n', 'y', 'k', 'h', 'y', 'n', 'E', 'v', 'g', 'e', 'n', 'y', '\0'};
    for (int i = 0; i < strlen(s3); i++)
        if (s.at(i) != s3[i])
            return false;
    return true;
}

bool test_raw() {
    char s1 [10] = {'K', 'o', 'r' , 'n', 'y', 'k', 'h', 'y', 'n', '\0'};
    String s(s1);
    return s.length() == strlen(s1);
}

bool test_memory() {
    char s[5] = {'m', 'e', 'm', 'o', '\0'};
    char s_app[3] = {'r', 'y', '0'};
    String s_res(s);
    s_res.append(s_app);
    return s_res.length() != strlen(s);
}

bool test_copy_constructor() {
    char st[5] = {'c', 'o', 'p', 'y', '\0'};
    String s1(st);
    String s2(s1);
    s2.append(st);
    return s2.length() != s1.length();
}

bool test_operator() {
    char str[5] = {'c', 'o', 'p', 'y', '\0'};
    String s1(str);
    String s2(nullptr);
    s2 = s1;
    s2.append(str);
    return s2.length() != s1.length();
}

int main(int argc, const char * argv[]) {
    cout << "test nullptr: " << test_nullptr() << endl;
    cout << "test length: " << test_length() << endl;
    cout << "test at: " << test_at() << endl;
    cout << "test append: " << test_append() << endl;
    cout << "test raw: " << test_raw() << endl;
    cout << "test memory: " << test_memory() << endl;
    cout << "test copy constructor: " << test_copy_constructor() << endl;
    cout << "test operator: " << test_operator() << endl;
    return 0;
}
