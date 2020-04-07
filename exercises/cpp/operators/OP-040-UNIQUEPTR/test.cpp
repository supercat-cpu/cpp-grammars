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

bool test_less () {
    int *pn1 = new int(20);
    IntUniquePtr p1(pn1);
    int *pn2 = new int(30);
    IntUniquePtr p2(pn2);
    return (p1 < p2) == (*pn1 < *pn2);
}

bool test_more () {
    int *pn1 = new int(20);
    IntUniquePtr p1(pn1);
    int *pn2 = new int(30);
    IntUniquePtr p2(pn2);
    return (p1 > p2) == (*pn1 > *pn2);
}

bool test_less_equal () {
    int *pn1 = new int(30);
    IntUniquePtr p1(pn1);
    int *pn2 = new int(30);
    IntUniquePtr p2(pn2);
    return (p1 <= p2) == (*pn1 <= *pn2);
}

bool test_more_equal () {
    int *pn1 = new int(20);
    IntUniquePtr p1(pn1);
    int *pn2 = new int(20);
    IntUniquePtr p2(pn2);
    return (p1 >= p2) == (*pn1 >= *pn2);
}

bool test_equal () {
    int *pn1 = new int(12);
    IntUniquePtr p1(pn1);
    int *pn2 = new int(13);
    IntUniquePtr p2(pn2);
    return (p1 == p2) == (*pn1 == *pn2);
}

bool test_not_equal () {
    int *pn1 = new int(23);
    IntUniquePtr p1(pn1);
    int *pn2 = new int(34);
    IntUniquePtr p2(pn2);
    return (p1 != p2) == (*pn1 != *pn2);
}

int main() {
    cout << "test 1: empty constructor " << test_empty() << endl;
    cout << "test 2: full constructor " << test_full() << endl;
    cout << "test 3: copy constructor " << test_copy() << endl;
    cout << "test 4: dereferencing " << test_deref() << endl;
    cout << "test 5: operation \"<\" " << test_less() << endl;
    cout << "test 6: operation \">\" " << test_more() << endl;
    cout << "test 7: operation \"<=\" " << test_less_equal() << endl;
    cout << "test 8: operation \">=\" " << test_more_equal() << endl;
    cout << "test 9: operation \"==\" " << test_equal() << endl;
    cout << "test 10: operation \"==\" " << test_not_equal() << endl;
    return 0;
}
