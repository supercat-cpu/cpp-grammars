#include "string.hpp"

#include <iostream>
#include <cstdio>
#include <cstring>

String::String(const char *c) {
    if (c == nullptr) {
        s = nullptr;
    } else {
        s = new char [strlen(c)];
        strcpy(s, c);
    }
}

String::String(const String &str) {
    if (str.raw() == nullptr) {
        s = nullptr;
    } else {
        s = new char [str.length()];
        strcpy(s, str.s);
    }
}

size_t String::length() const {
    if (s != nullptr)
        return strlen(s);
    else
        return -1;
}

char &String::at(size_t index) {
    return s[index];
}

void String::append(char *scat) {
    if (scat != nullptr && s != nullptr)
        strcat(s, scat);
}

char *String::raw() const {
    return s;
}

String& String::operator = (const String &str) {
    if (str.raw() == nullptr) {
        s = nullptr;
    } else {
        s = new char [str.length()];
        strcpy(s, str.s);
    }
    return *this;
}

String:: ~String() {
    if (s != nullptr)
        delete [] s;
}

