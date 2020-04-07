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
    s = new char [str.length()];
    strcpy(s, str.s);
}

size_t String::length() const {
    return strlen(s);
}

char &String::at(size_t index) const {
    return s[index];
}

void String::append(char *scat) {
    strcat(s, scat);
}

char *String::raw() const {
    return s;
}

String& String::operator = (const String &str) {
    s = new char [str.length()];
    strcpy(s, str.s);
    return *this;
}

String:: ~String() {
    delete [] s;
}

