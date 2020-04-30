#include <iostream>
#include <cstdio>
#include "string.hpp"
#include <cstring>

using namespace std;


bool test_nullptr_constr() {
    char *s_null = nullptr;
    String s(s_null);
    return s.raw() == s_null;
}

bool test_nullptr_op() {
    char *s_null = nullptr;
    char s [] = "abc";
    String s1(s);
    String s2(s_null);
    s1 = s2;
    return s1.raw() == s_null;
}

bool test_nullptr_length() {
    char *s_null = nullptr;
    String s(s_null);
    return s.length() == -1;
}

bool test_nullptr_append() {
    char *s_null = nullptr;
    char s [] = "abc";
    String s1(s_null);
    s1.append(s);
    return s1.raw() == s_null;
}

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
    s2.append(st);
    return s2.length() != s1.length();
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
    cout << "test nullptr lenght: " << test_nullptr_length() << endl;
    cout << "test empty length: " << test_length_empty() << endl;
    
    cout << "test at: " << test_at() << endl;
    
    cout << "test append: " << test_append() << endl;
    cout << "test nullptr append: " << test_nullptr_append() << endl;
    
    cout << "test raw: " << test_raw() << endl;
    
    cout << "test copy constructor: " << test_copy_constructor() << endl;
    cout << "test nullptr copy constructor: " << test_nullptr_constr() << endl;
    
    cout << "test operator: " << test_operator() << endl;
    cout << "test nullptr operator: " << test_nullptr_op() << endl;
    return 0;
}
