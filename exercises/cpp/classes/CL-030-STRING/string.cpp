//
//  string.cpp
//  cl-030-string
//
//  Created by Екатерина Евдокимова on 30.03.20.
//  Copyright © 2020 Екатерина Евдокимова. All rights reserved.
//

#include "string.hpp"

#include <iostream>
#include <cstdio>

String::String(const char *c) {
    if (c == nullptr) {
        s = nullptr;
    } else {
        s = new char [strlen(c)];
        strcpy(s, c);
    }
}

size_t String::length() {
    return strlen(s);
}

char &String::at(size_t index) {
    return s[index];
}

void String::append(char *scat) {
    strcat(s, scat);
}

const char *String::raw() {
    return s;
}

String:: ~String() {
    delete [] s;
}

