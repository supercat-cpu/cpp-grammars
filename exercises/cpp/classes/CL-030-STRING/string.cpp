#include "string.hpp"

#include <iostream>
#include <cstdio>
#include <cstring>

String::String(const char *c) {
    if (c == nullptr) {
        s = nullptr;
    } else {
        s = new char [strlen(c) + 1];
        strcpy(s, c);
    }
}

String::String(const String &str) {
    if (str.raw() == nullptr) {
        s = nullptr;
    } else {
        s = new char [str.length() + 1];
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
    {
        char * tmp = new char [strlen(s) + strlen(scat) + 1];
        strcat(tmp, s);
        strcat(tmp, scat);
        delete [] s;
        s = tmp;
    }
}

char *String::raw() const {
    return s;
}

String& String::operator = (const String &str) {
    delete [] s;
    if (str.raw() == nullptr) {
        s = nullptr;
    } else {
        s = new char [str.length() + 1];
        for (int i = 0; i < strlen(s) + 1; i++ )
        {
            s[i] = str.s[i];
        }
    }
    return *this;
}

String:: ~String() {
    if (s != nullptr)
        delete [] s;
}
