#ifndef string_h
#define string_h

#include <cstdio>

class String {
    char *s;
public:
    String(const char *c);
    String(const String &s);
    size_t length() const;
    char &at(size_t index);
    void append(char *);
    char * raw() const;
    String& operator = (const String &s);
    ~String();
};

#endif
