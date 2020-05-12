#include <iostream>
#include <cstdio>
#include "uniqueptr.hpp"

using namespace std;

bool test_empty () {
    IntUniquePtr p;
    return p.getraw() == nullptr;
}

bool test_full () {
    int *pn = new int;
    IntUniquePtr p(pn);
    return p.getraw() == pn;
}

bool test_copy () {
    int *pn1 = new int;
    IntUniquePtr p1(pn1);
    IntUniquePtr p2(p1);
    return (p2.getraw() == pn1 && p1.getraw() == nullptr);
}

bool test_deref () {
    int *p = new int;
    *p = 5;
    IntUniquePtr pt(p);
    return *pt == *p;
}

int main() {
    cout << "test 1: empty constructor " << test_empty() << endl;
    cout << "test 2: full constructor " << test_full() << endl;
    cout << "test 3: copy constructor " << test_copy() << endl;
    cout << "test 4: dereferencing " << test_deref() << endl;
    return 0;
}
