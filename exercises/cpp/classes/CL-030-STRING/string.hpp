//
//  string.hpp
//  cl-030-string
//
//  Created by Екатерина Евдокимова on 30.03.20.
//  Copyright © 2020 Екатерина Евдокимова. All rights reserved.
//

#ifndef string_h
#define string_h

#include <iostream>
#include <cstdio>

class String {
    char *s;
public:
    String(const char *c);
    size_t length();
    char &at(size_t index);
    void append(char *);
    const char * raw();
    ~String();
};

#endif /* string_h */
