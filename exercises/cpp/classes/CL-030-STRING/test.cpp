#include <iostream>
#include <cstdio>
#include "string.hpp"
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

int main(int argc, const char * argv[]) {
    cout << "test nullptr: " << test_nullptr() << endl;
    cout << "test length: " << test_length() << endl;
    cout << "test at: " << test_at() << endl;
    cout << "test append: " << test_append() << endl;
    cout << "test raw: " << test_raw() << endl;
    return 0;
}
